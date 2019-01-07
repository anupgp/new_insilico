/*
  core/configuration/observer.hpp - Simulation output observer

  Copyright (C) 2015 Pranav Kulkarni, Collins Assisi Lab, IISER, Pune
  <pranavcode@gmail.com>

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

#ifndef INCLUDE_NEWINSILICO_CONFIGURATION_OBSERVER_HPP
#define INCLUDE_NEWINSILICO_CONFIGURATION_OBSERVER_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "include/type.hpp"

namespace newinsilico {

  auto set_observe_delimiter(const char _delim) -> void; 
  void  set_write_this_interval(const bool _flag);
  void  set_write_this_interval2(const bool _flag);
  auto set_observe_header(const bool _flag) -> void; 
  auto set_observe_step_interval(const unsigned _write_interval) -> void;
  auto build_header_once() -> void; 
  auto write_header_once() -> void; 
  struct observer {
    auto operator() (newinsilico::state_type &variables, const double t) -> void; 
  };
  auto observe(std::string _variable) -> void;
  auto observe_neuron(unsigned id, std::string _variable) -> void;
  auto observe_neuron(std::vector<unsigned> ids, std::string _variable) -> void;
  auto observe_synapse(unsigned id, std::string _variable) -> void;
  auto observe_synapse(std::vector<unsigned> ids, std::string _variable) -> void;

} // namespace newinsilico

#endif
