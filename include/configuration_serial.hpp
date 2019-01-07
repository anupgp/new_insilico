/*
 core/configuration/serial.hpp - insilico configuration serial file handling header and source

 Copyright (C) 2014 Collins Assisi, Collins Assisi Lab, IISER, Pune
 Copyright (C) 2014-2015 Pranav Kulkarni, Collins Assisi Lab, IISER, Pune <pranavcode@gmail.com>

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

#ifndef INCLUDE_NEWINSILICO_CONFIGURATION_SERIAL_HPP
#define INCLUDE_NEWINSILICO_CONFIGURATION_SERIAL_HPP

#include "include/engine.hpp"
#include "include/helper_file.hpp"
#include "include/helper_string.hpp"

#include "include/configuration_observer.hpp"
#include "include/configuration_parser.hpp"
#include "include/injector.hpp"
#include "include/dynamic_params.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace newinsilico {

// initialization, check and handle commandline arguments
  void initialize(int argc, char **argv);

// close all output streams
  void finalize();

} // namespace newinsilico

#endif
