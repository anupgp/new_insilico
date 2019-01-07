/*
  core/dynamic_params.hpp - insilico's dynamic parameters supplier

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

#include <cmath>
#include <algorithm>

#include "include/dynamic_params_parser.hpp"
#include "include/helper_floating_comp.hpp"
#include "include/dynamic_params.hpp"
#include "include/data.hpp"

namespace newinsilico
{
  
  bool found_dynparam_name = false;
  bool found_dynparam_value = false;
    
  auto value(const std::string& _param, const double _time) -> double {
    // std::cout << "Call to value\n";
    double param_val = 0;
    // Checks if there is a time_seq from the dynamic_params file
    if(!time_seq.empty()) {
      // std::cout << "time_seq_not empty!\n";
      // Checks if the parameter name is in the dynamic_params file
      auto param_it = dynamic_params_seq.find(_param);
      if (param_it != dynamic_params_seq.end()){
	found_dynparam_name = true;
	// std::cout << "Param found\n";
	// If param name is found, get the first value from the time sequence
	double firstval = *time_seq.begin();
	double lastval = *(time_seq.end()-1);
	// Check if the key time is greater than or equal to first element in seq_time
	if ((_time >= firstval) && (_time <= lastval)){
	  // Search for the first element in the time_seq that is greater than the key time value (_time + firstval)
	  auto time_it = std::upper_bound(time_seq.begin(), time_seq.end(), _time);
	  // std::cout << "Found time: " << *time_it << " ";
	  // If a time_seq with equal or greater element is found
	  if (time_it != time_seq.end()){
	    unsigned idx = time_it - time_seq.begin() - 1;
	    param_val = param_it->second[idx];
	    found_dynparam_value = true;
	  }
	}
	else{
	  found_dynparam_value = false;
	}
      }
    }

    return param_val;
  }
}
