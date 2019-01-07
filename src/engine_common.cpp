/*
  core/engine/serial/common.hpp - Common data handlers for engine header and source

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

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "include/type.hpp"
#include "include/data.hpp"
#include "include/engine_common.hpp"

namespace newinsilico

{
  
  std::vector< unsigned > prepopulated_neuron_ids;
  std::vector< unsigned > prepopulated_synapse_ids;
  state_type var_noise;
  state_type var_vals;


  auto get_variables() -> state_type {
    return var_vals;
  }

  auto get_noise() -> state_type {
    return var_noise;
  }

  auto neuron_count() -> unsigned {
    if(prepopulated_neuron_ids.empty())
      return 0;
    return (prepopulated_neuron_ids.back() + 1);
  }

  auto synapse_count() -> unsigned {
    if(prepopulated_synapse_ids.empty())
      return 0;
    return (prepopulated_synapse_ids.back() + 1);
  }
  
}
