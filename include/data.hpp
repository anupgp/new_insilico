/*
  core/engine/data.hpp - insilico engine data header

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

#ifndef INCLUDE_NEWINSILICO_DATA_HPP
#define INCLUDE_NEWINSILICO_DATA_HPP

#include "include/type.hpp"

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace newinsilico {

  extern bool found_dynparam_name;
  extern bool found_dynparam_value;
  extern std::unordered_map<std::string, std::vector<double>> dynamic_params_seq;
  extern std::vector<double> time_seq;
  extern std::vector<std::string> params_seq;
  extern std::vector< Neuron* > neuron_objects;
  extern std::vector< unsigned > neuron_objects_count;
  extern std::vector< Synapse*> synapse_objects;
  extern std::vector< unsigned > synapse_objects_count;
  const double __acceptable_error = 25e-6;
  extern std::vector<std::vector<double>> external_current_seq;
  extern std::vector<double> time_seq;
  extern std::vector<unsigned> neurons_seq;
  extern std::unordered_map< std::string, unsigned > index_map;
  extern std::unordered_map< std::string, double > value_map;
  extern std::vector< unsigned > neuron_start_list_ids;
  extern std::vector< unsigned > neuron_end_list_ids;
  extern std::vector< unsigned > prepopulated_neuron_ids;
  extern std::vector< unsigned > prepopulated_synapse_ids;
  extern std::vector< unsigned > synapse_start_list_ids;
  extern std::vector< unsigned > synapse_end_list_ids;
  extern std::vector< std::vector< unsigned > > pre_synaptic_lists;
  extern std::vector< unsigned > pre_neuron;
  extern std::vector< unsigned > post_neuron;
  extern std::vector< std::string > var_list_ids;
  extern state_type var_vals;
  extern state_type var_noise;
  extern char observer_delimiter;
  extern bool observer_header;
  // extern std::vector<unsigned> neuron_indices;
  // extern std::vector<unsigned> synapse_indices;
} //namespace newinsilico

#endif
