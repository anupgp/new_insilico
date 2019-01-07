/*
  core/engine/generate.hpp - Type generation and management

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

#ifndef INCLUDE_NEWINSILICO_GENERATE_HPP
#define INCLUDE_NEWINSILICO_GENERATE_HPP

#include <boost/numeric/odeint.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "include/type.hpp"
#include "include/driver.hpp"

namespace newinsilico {

  template<typename T>
  auto generate_neuron(unsigned count) -> void
  {
    // neuron_objects.push_back(std::unique_ptr<T>(new T()));
    // neuron_objects.push_back(std::make_unique<T>());
    // neuron_objects.push_back(new T());
    neuron_objects_count.push_back(count);
  }
  template<typename T>
  auto generate_synapse(unsigned count) -> void
  {
    // synapse_objects.push_back(std::unique_ptr<T>(new T()));
    synapse_objects.push_back(new T());
    // synapse_objects.push_back(std::make_unique<T>());
    synapse_objects_count.push_back(count);
  }

} // namespace newinsilico

#endif
