#include <algorithm>

#include "include/helper_string.hpp"

namespace newinsilico
{

  // trim string from beginning (left)
  auto ltrim(std::string &s) -> void {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
  }

  // trim string from ending (right)
  auto rtrim(std::string &s) -> void {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
  }

  // trim string from both the ends
  auto trim(std::string &s) -> void {
    rtrim(s);
    ltrim(s);
  }

  // convert string literal to double precision floating point number
  auto string_to_double(std::string strnum) -> double {
    double value;
    try {
      value = ::atof(strnum.c_str());
    }
    catch(const std::exception& e) {
      std::cerr << "[newinsilico::] Simulation Exception: "
		<< "supplied with file that contains improper value: "<< strnum <<'\n';
      exit(1);
    }
    return value;
  }

  // check if the string (subject) starts with given sub string (test)
  auto starts_with(const std::string &subject, const std::string &test) -> bool {
    return (test.length() <= subject.length())  &&
      (equal(test.begin(), test.end(), subject.begin()));
  }

  // inplace string split 
  auto split(const std::string &s, char delim, std::vector<std::string> &elems) -> void {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
      elems.push_back(item);
    }
  }

  // split string and return vector
  auto split(const std::string &s, char delim) -> std::vector< std::string > {
    std::vector< std::string > elems;
    split(s, delim, elems);
    return elems;
  }
}

