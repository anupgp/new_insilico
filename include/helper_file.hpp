/*
 core/helper/file.hpp - String manipulation helper header and source

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

#ifndef INCLUDE_NEWINSILICO_HELPER_FILE_HPP
#define INCLUDE_NEWINSILICO_HELPER_FILE_HPP

#include <iostream>
#include <fstream>
#include <string>

namespace newinsilico {

// check if the file is present and is permitted to open
  bool file_check(const std::ifstream &stream, const std::string &filename);
} // namespace insilico

#endif
