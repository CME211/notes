// c standard includes
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>

// c++ standard includes
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <unordered_map>

// declare types for data
typedef uint32_t MovieId;
typedef uint32_t UserId;
typedef uint32_t Rating;
typedef std::unordered_map<UserId,Rating> UserRatingMap;
// (movies need to be in order of movie id)
typedef std::map<MovieId,UserRatingMap> MovieRatingMap;
typedef std::unordered_map<UserId,double> AverageUserRating;

void load_data(std::string inputfile,
               MovieRatingMap& movies,
               AverageUserRating& users) {
  // clear out old data
  movies.clear();
  users.clear();
  
  // intermediate maps for loading data
  UserRatingMap user_rating_sum;
  UserRatingMap user_rating_count;

  std::ifstream f(inputfile);
  if (f.is_open()) {
    UserId user_id;
    MovieId movie_id;
    Rating rating;
    uint32_t time_stamp;
    uint32_t nlines = 0;
    while (f >> user_id >> movie_id >> rating >> time_stamp) {
      movies[movie_id][user_id] = rating;
      user_rating_sum[user_id] += rating;
      user_rating_count[user_id] += 1;
      nlines += 1;
    }
    for (auto& uc : user_rating_count) {
      users[uc.first] = double(user_rating_sum[uc.first]) / double(uc.second);
    }
    std::cout << "Read " << nlines << " lines with total of " << movies.size()
              << " movies and " << users.size() << " users" << std::endl;
    f.close();
  }
  else {
    std::cout << "Could not open input file: " << inputfile << std::endl;
    std::exit(1);
  }
}

void compute_acs(UserRatingMap& movie1,
                 UserRatingMap& movie2,
                 AverageUserRating& users,
                 double& acs,
                 uint32_t& ncommon) {
  // initialize numerator and denominator terms
  double num = 0.0;  // numerator
  double den1 = 0.0; // denominator term for movie1
  double den2 = 0.0; // denominator term for movie2

  ncommon = 0;
  for (auto& ur1 : movie1) {
    auto ur2 = movie2.find(ur1.first);
    if ( ur2 != movie2.end()) {
      // user is in both maps
      double useravg = users[ur1.first];
      num += (ur1.second-useravg)*(ur2->second-useravg);
      den1 += (ur1.second-useravg)*(ur1.second-useravg);
      den2 += (ur2->second-useravg)*(ur2->second-useravg);
      ncommon += 1;
    }
  }
  acs = num / sqrt(den1*den2 + 1.0e-6);
}

void compute_similarities(
    MovieRatingMap& movies,
    AverageUserRating& users,
    uint32_t userthreshold,
    std::string outputfile) {

  // open the output file
  std::ofstream f(outputfile);
  if (!f.is_open()) {
    std::cout << "Could not open output file: " << outputfile << std::endl;
    std::exit(1);
  }

  // set precision for floating point numbers
  f.setf(std::ios::fixed, std::ios::floatfield);
  f.setf(std::ios::showpoint);
  f.precision(2);
  
  // loop through movies
  std::clock_t start = std::clock();
  for (auto& mr1 : movies) {

    // variables to record similar movie
    bool has_similar = false;
    MovieId similar_movie = 0;
    double similarity = 0.0;
    uint32_t similar_ncommon = 0;

    for (auto& mr2 : movies) {
      // skip case when mr1 and mr2 are the same
      if (mr1.first == mr2.first) {
        continue;
      }

      double acs = 0.0;
      uint32_t ncommon = 0;
  
      // compute similarity
      compute_acs(mr1.second,mr2.second,users,acs,ncommon);

      if (ncommon >= userthreshold and (not has_similar or acs > similarity)) {
        has_similar = true;
        similarity = acs;
        similar_movie = mr2.first;
        similar_ncommon = ncommon;
      }
    }

    // output for movie
    f << mr1.first;
    if (has_similar) {
      f << " (" << similar_movie << "," << similarity << "," << similar_ncommon
        << ")";
    }
    f << std::endl;
  }
  std::clock_t finish = std::clock();
  std::cout.setf(std::ios::fixed, std::ios::floatfield);
  std::cout.setf(std::ios::showpoint);
  std::cout.precision(2);
  std::cout << "Computed similarities in "
            << double(finish-start)/CLOCKS_PER_SEC << " seconds" << std::endl;
  f.close();
}

int main(int argc, char* argv[]) {
  using std::cout;
  using std::endl;
  
  if (argc < 3) {
    cout << "Usage:" << endl;
    cout << argv[0] <<
        "<MovieLens file> <similarities file> [user thresh (default = 5)]"
         << endl;
    return 0;
  }

  std::string inputfile = argv[1];
  std::string outputfile = argv[2];
  
  uint32_t userthreshold = 5;

  // get optional command line specified user threshold
  if (argc == 4) {
    userthreshold = (uint32_t)atoi(argv[3]);
  }

  cout << "Input MovieLens file: " << inputfile << endl;
  cout << "Output file for similarity data: " << outputfile << endl;
  cout << "Minimum number of common users: " << userthreshold << endl;

  AverageUserRating users;
  MovieRatingMap movies;

  load_data(inputfile,movies,users);
  compute_similarities(movies,users,userthreshold,outputfile);
  
  return 0;
}
