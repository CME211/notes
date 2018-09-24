#ifndef NAMES_HPP
#define NAMES_HPP

#include <string>
#include <tuple>
#include <unordered_map>

typedef std::unordered_map<std::string,std::tuple<double,double,unsigned int>> namemap;

class NameClassifier
{
  namemap female;
  namemap male;

  void readData(std::string filename, namemap &names);

 public:
  NameClassifier(std::string female, std::string male);
  double classifyName(std::string name);
  namemap::size_type getNumberNames(void);
  namemap::size_type getNumberFemaleNames(void);
  namemap::size_type getNumberMaleNames(void);
};

#endif /* NAMES_HPP */
