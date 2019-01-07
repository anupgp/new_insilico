/*
 core/helper/string.hpp - String manipulation helper header and source

 Copyright (C) 2015 Pranav Kulkarni, Collins Assisi Lab, IISER, Pune <pranavcode@gmail.com>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef INCLUDE_NEWINSILICO_HELPER_STRING_HPP
#define INCLUDE_NEWINSILICO_HELPER_STRING_HPP

#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>

namespace newinsilico {

// trim string from beginning (left)
  auto ltrim(std::string &s) -> void;

// trim string from ending (right)
  auto rtrim(std::string &s) -> void;

// trim string from both the ends
  auto trim(std::string &s) -> void;

// convert string literal to double precision floating point number
  auto string_to_double(std::string strnum) -> double;

// check if the string (subject) starts with given sub string (test)
 auto starts_with(const std::string &subject, const std::string &test) -> bool;

// inplace string split 
  auto split(const std::string &s, char delim, std::vector<std::string> &elems) -> void;

// split string and return vector
  auto split(const std::string &s, char delim) -> std::vector< std::string >;

} // namespace newinsilico

#endif
