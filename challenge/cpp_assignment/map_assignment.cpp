// c++ standard includes
#include <fstream>
#include <iostream>
#include <map>
#include <string>

// declare types for data
typedef uint32_t MovieId;
typedef uint32_t UserId;
typedef uint32_t Rating;
typedef std::map<UserId,Rating> UserRatingMap;
typedef std::map<MovieId,UserRatingMap> MovieRatingMap;

// generic printer for a map
// pass output to python -m json.tool
template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<K,V>& m) {
  os << "{";
  bool comma = false;
  for (const auto& kv : m) {
    if (comma) {
      os << ",";
    }  else {
      comma = true;
    }
    os << "\"" << kv.first << "\":" << kv.second;
  }
  os << "}";
  return os;
}

int main() {

  std::string inputfile = "u.data.short";
  std::ifstream f(inputfile);

  MovieRatingMap movies;
  
  if (f.is_open()) {
    UserId user_id;
    MovieId movie_id;
    Rating rating;
    uint32_t time_stamp;
    while (f >> user_id >> movie_id >> rating >> time_stamp) {
      movies[movie_id][user_id] = rating;
    }
    f.close();
  }
  else {
    std::cout << "Could not open input file: " << inputfile << std::endl;
    std::exit(1);
  }

  MovieRatingMap movies2 = movies;

  // modify movies
  movies[242][196] = 5;  // change something that exists
  movies[100][100] = 99; // change something that does not exist

  // print movies
  std::cout << "{\"movies\":" << movies << ",";
  // print movies2
  std::cout << "\"movies2\":" << movies2 << "}";
  std::cout << std::endl;
}
