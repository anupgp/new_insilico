#include <iostream>
#include <vector>

#include "include/type.hpp"

namespace newinsilico
{

  void Neuron::ode_set(state_type &, state_type &, const double, const unsigned) {
    std::cerr << "*** Your Neuron class or Neuron ode_set function is not well-formed ***\n";
  }
  void Neuron::ode_set(state_type &, state_type &, state_type &, const double, const unsigned) {
    std::cerr << "*** Your Neuron class or Neuron ode_set_noise function is not well-formed ***\n";
  }
  Neuron::~Neuron(){}

  void Synapse::ode_set(state_type &, state_type &, const double, const unsigned) {
    std::cerr << "*** Your Synapse class or Synapse ode_set function is not well-formed ***\n";
  }
  void Synapse::ode_set(state_type &, state_type &, state_type &, const double, const unsigned) {
    std::cerr << "*** Your Synapse class or Synapse ode_set_noise function is not well-formed ***\n";
  }
  Synapse::~Synapse(){};

}
