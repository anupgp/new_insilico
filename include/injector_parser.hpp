/*
  core/injector/parser.hpp - insilico Current injector's parsing
  capability header and source

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

#ifndef INCLUDE_NEWINSILICO_INJECTOR_PARSER_HPP
#define INCLUDE_NEWINSILICO_INJECTOR_PARSER_HPP

#include "include/helper_file.hpp"
#include "include/helper_string.hpp"

#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

namespace newinsilico {

  void read_external_current(const std::string &external_current_file);

} // namespace newinsilico

#endif
