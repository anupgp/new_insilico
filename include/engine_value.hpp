/*
  core/engine/serial/value.hpp - insilico engine serial API

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

#ifndef INCLUDE_NEWINSILICO_ENGINE_VALUE_HPP
#define INCLUDE_NEWINSILICO_ENGINE_VALUE_HPP

#include "type.hpp"
#include "data.hpp"
#include "engine_common.hpp"

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace newinsilico {

  auto value_key_present(char* key) -> bool;
  auto neuron_value(unsigned _id, std::string _variable) -> double;
  auto synapse_value(unsigned _id, std::string _variable) -> double;
  auto neuron_value(unsigned _id, std::string _variable, bool& error) -> double;
  auto neuron_value(unsigned _id, std::string _variable, double value) -> void;
  auto synapse_value(unsigned _id, std::string _variable, bool& error) -> double;
  auto synapse_value(unsigned _id, std::string _variable, double value) -> void;
  auto get_neuron_values(std::string _variable) -> std::vector< double >;
  auto get_synapse_values(std::string _variable) -> std::vector< double >;
  auto get_values(std::string _variable) -> std::vector< double >;
  auto get_pre_neuron_values(unsigned _id, std::string _variable) -> std::vector<double>;
  auto neuron_value_key(unsigned _id, std::string _variable) -> decltype(std::string());
  auto synapse_value_key(unsigned _id, std::string _variable) -> decltype(std::string());
  auto get_neuron_value_keys(std::string _variable) -> std::vector<std::string>;
  auto get_synapse_value_keys(std::string _variable) -> std::vector<std::string>;
  auto get_value_keys(std::string _variable) -> std::vector<std::string>;

} // namespace newinsilico

#endif
