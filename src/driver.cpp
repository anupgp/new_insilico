#include <vector>

#include "include/type.hpp"
#include "include/driver.hpp"
#include "include/generate.hpp"
#include "include/data.hpp"

namespace newinsilico
{
  std::vector< Neuron* > neuron_objects;
  std::vector< unsigned > neuron_objects_count;
  std::vector< Synapse*> synapse_objects;
  std::vector< unsigned > synapse_objects_count;
  
  auto driver::operator()(state_type &_state, state_type &_dxdt, const double _t) -> void 
  {
    unsigned ultimate_count = 0;
    for(std::vector<Neuron*>::size_type type = 0; type < neuron_objects.size(); ++type) {
      for(unsigned iter = 0; iter < neuron_objects_count[type]; ++iter, ++ultimate_count) {
	neuron_objects[type] -> ode_set(_state, _dxdt, _t, ultimate_count);
      }
    }
    ultimate_count = 0;
    for(std::vector<Synapse*>::size_type type = 0; type < synapse_objects.size(); ++type) {
      for(unsigned iter = 0; iter < synapse_objects_count[type]; ++iter, ++ultimate_count) {
	synapse_objects[type] -> ode_set(_state, _dxdt, _t, ultimate_count);
      }
    }
  }
  // ---------------------------------------
  // Overloaded operator for stochastic euler
  auto driver::operator()(state_type &_state, state_type &_dxdt,  state_type &_noise, const double _t) -> void {
    unsigned ultimate_count = 0;
    for(std::vector<Neuron*>::size_type type = 0; type < neuron_objects.size(); ++type) {
      for(unsigned iter = 0; iter < neuron_objects_count[type]; ++iter, ++ultimate_count) {
	neuron_objects[type] -> ode_set(_state, _dxdt, _noise, _t, ultimate_count);
      }
    }
    ultimate_count = 0;
    for(std::vector<Synapse*>::size_type type = 0; type < synapse_objects.size(); ++type) {
      for(unsigned iter = 0; iter < synapse_objects_count[type]; ++iter, ++ultimate_count) {
	synapse_objects[type] -> ode_set(_state, _dxdt, _noise, _t, ultimate_count);
      }
    }
  }
}
