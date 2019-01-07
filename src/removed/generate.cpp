#include <vector>
#include <algorithm>

#include "include/generate.hpp"
#include "include/data.hpp"

namespace newinsilico
{
  template<typename T>
  auto generate_neuron(unsigned count) -> void {
    // neuron_objects.push_back(std::unique_ptr<T>(new T()));
    // neuron_objects.push_back(std::make_unique<T>());
    // neuron_objects.push_back(new T());
    neuron_objects_count.push_back(count);
  }

  template<typename T>
  auto generate_synapse(unsigned count) -> void {
    // synapse_objects.push_back(std::unique_ptr<T>(new T()));
    synapse_objects.push_back(new T());
    // synapse_objects.push_back(std::make_unique<T>());
    synapse_objects_count.push_back(count);
  }
}
