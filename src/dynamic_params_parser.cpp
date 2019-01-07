/*
  core/dynamic_params/parser.hpp - insilico dynamic parameters' parsing

  Copyright (C) 2015 Pranav Kulkarni, Collins Assisi Lab,
  IISER, Pune <pranavcode@gmail.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

#include "include/dynamic_params_parser.hpp"
#include "include/helper_string.hpp"
#include "include/data.hpp"

namespace newinsilico
{
  std::unordered_map<std::string, std::vector<double>> dynamic_params_seq;
  // std::vector<double> time_seq;
  std::vector<std::string> params_seq;
  
  void read_dynamic_params(const std::string &_param_file) {
    char linedelim = '\n';
    char worddelim = ',';
    std::string aline;
    std::stringstream ss;
    std::string aword;
    std::vector<double> seq;
    // std::string::size_type sz;     // alias of size_t
    // char * pend;
    std::ifstream param_file_stream(_param_file);
    if(param_file_stream.is_open() == false){
      std::cerr << "The file does not exist!" << "\n";
      return;
    }
    while(getline(param_file_stream, aline, linedelim)) { // read a line
      trim(aline);
      ss.clear();
      ss.str("");
      ss.str(aline);
      if((aline.length() > 0) && starts_with(aline,"time")) { 	// Get parameter names
	while(getline(ss, aword, worddelim)) {
	  if(aword.compare("time") == 0) continue;
	  params_seq.push_back(aword);
	}
      }
      else if((aline.length() > 0)) { 	// Get values
	seq.clear();
	while(std::getline(ss, aword, worddelim)) { // read the param
	  // std::cout << aword << " ";
	  std::cout.precision(10);
	  // std::cout << std::scientific;
	  trim(aword);
	  // seq.push_back(strtold(aword.c_str(),&pend));
	  seq.push_back(stod(aword));
	}
	// Push the first value to time_seq and remove the first element of seq
	time_seq.push_back(seq[0]);
	seq.erase(seq.begin(),seq.begin()+1);
	// Iterate over the parameters and push the element to the map
	typename std::vector<double>::iterator it_seq = seq.begin();
	for(auto el:params_seq){
	  dynamic_params_seq[el].push_back(*it_seq);
	  it_seq++;
	}
      }
    }
    // ------------------
    std::cout << "Dynamic parameter reading is success!\n";
  }
}
