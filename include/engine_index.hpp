/*
  core/engine/serial/index.hpp - engine serial index management API source

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
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef INCLUDE_NEWINSILICO_ENGINE_INDEX_HPP
#define INCLUDE_NEWINSILICO_ENGINE_INDEX_HPP

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "include/type.hpp"
#include "include/data.hpp"
#include "include/engine_common.hpp"

namespace newinsilico {

  auto get_neuron_index(unsigned _id, std::string _variable) -> unsigned;
  auto get_synapse_index(unsigned _id, std::string _variable) -> unsigned;
  auto get_neuron_index(unsigned _id, std::string _variable, bool& error) -> unsigned;
  auto get_synapse_index(unsigned _id, std::string _variable, bool& error) -> unsigned;
  auto get_neuron_indices(std::string _variable) -> std::vector<unsigned>; 
  auto get_synapse_indices(std::string _variable) -> std::vector<unsigned>;
  auto get_indices(std::string _variable) -> std::vector<unsigned>;
  auto neuron_id_from_index(unsigned _index) -> unsigned;
  auto neuron_id_from_index(unsigned _index, bool &error) -> unsigned;
  auto synapse_id_from_index(unsigned _index) -> unsigned;
  auto synapse_id_from_index(unsigned _index, bool &error) -> unsigned;
  auto variable_name_from_index(unsigned _index) -> std::string;
  auto get_pre_neuron_indices(unsigned _id, std::string _variable) -> std::vector<unsigned> ;

} // namespace newinsilico

#endif
