#include <vector>
#include <algorithm>

#include "include/engine.hpp"
#include "include/data.hpp"

namespace newinsilico
{
  std::vector< std::vector< unsigned > > pre_synaptic_lists;
  std::vector< unsigned > pre_neuron;
  std::vector< unsigned > post_neuron;
  
auto populate_pre_synaptic_lists() -> void {
  if(!post_neuron.empty()) {
    pre_synaptic_lists.resize( *max_element(post_neuron.begin(), post_neuron.end()) + 1 );
    for(unsigned iterator = 0; iterator < post_neuron.size(); ++iterator) {
      pre_synaptic_lists[ post_neuron[iterator] ].push_back( iterator );
    }
  }
}
}
