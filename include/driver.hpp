/*
  core/engine/driver.hpp - Solver trigger for integration and non-integration

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

#ifndef INCLUDE_NEWINSILICO_DRIVER_HPP
#define INCLUDE_NEWINSILICO_DRIVER_HPP

#include <iostream>
#include <vector>

#include "include/type.hpp"
#include "include/data.hpp"

namespace newinsilico {

  class driver {
  public:
    void operator()(state_type &variables, state_type &dxdt, const double time);
    void operator()(state_type &variables, state_type &dxdt, state_type &noises, const double time);
  };

} // namespace newinsilico

#endif
