/*
 core/configuration/parser.hpp - insilico's Configuration
                                 parser header and source

 Copyright (C) 2014-2015 Pranav Kulkarni, Collins Assisi Lab,
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
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef INCLUDE_NEWINSILICO_CONFIGURATION_PARSER_HPP
#define INCLUDE_NEWINSILICO_CONFIGURATION_PARSER_HPP

#include "include/helper_file.hpp"
#include "include/helper_string.hpp"
#include "include/data.hpp"
#include "include/engine.hpp"

#include <sstream>
#include <string>

namespace newinsilico {

    // clean input file inputs
    std::string remove_comments(std::string &with_comments);
    void read_neuron_synapse(const std::string neuron_file, const std::string synapse_file=""); 

} // namespace newinsilico

#endif
