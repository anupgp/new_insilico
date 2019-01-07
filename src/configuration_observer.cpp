#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

#include "include/configuration_observer.hpp"
#include "include/engine_common.hpp"
#include "include/engine_index.hpp"
#include "include/engine_value.hpp"
#include "include/type.hpp"
#include "include/data.hpp"

namespace newinsilico
{

  // global variables definition
  std::vector< std::string > observation_header;
  std::vector< std::string > pre_computed_keys;
  // std::vector<unsigned> neuron_indices;
  // std::vector<unsigned> synapse_indices;
  std::vector< int > pre_computed_indices;
  std::ofstream outstream;
  std::stringstream write_buffer;
  bool header_observed_flag = false;
  bool write_interval_feature= false;
  bool write_this_interval = true;
  bool write_this_interval2 = false;
  unsigned write_interval= 0;
  unsigned step_ctr = 0;
  unsigned write_ctr = 0;
  char observer_delimiter = ',';
  bool observer_header = true;

  // global variables initialize
  // header_observed_flag = false;
  // write_interval_feature = false;
  // write_this_interval = true;
  // write_this_interval2 = false;
  // write_interval = 0;
  // step_ctr = 0;
  // write_ctr = 0;
  // observer_delimiter = ',';
  // observer_header = true;    

  auto set_observe_delimiter(const char _delim) -> void {
    observer_delimiter = _delim;
  }

  void  set_write_this_interval(const bool _flag){
    write_this_interval = _flag;
  }

  void  set_write_this_interval2(const bool _flag){
    write_this_interval2 = _flag;
  }
    
  auto set_observe_header(const bool _flag) -> void {
    observer_header = _flag;
  }

  auto set_observe_step_interval(const unsigned _write_interval) -> void {
    write_interval = _write_interval;
    write_interval_feature = true;
  }

  auto build_header_once() -> void {
    char key[128];
    bool error = false;
    unsigned id;
    std::string var;
    for(unsigned index : pre_computed_indices) {
      id = neuron_id_from_index(index, error);
      if(!error) {
	var = variable_name_from_index(index);
	sprintf(key, "n%d%s", id, var.c_str());
	observation_header.push_back(key);
      }
      else {
	id = synapse_id_from_index(index, error);
	if(!error) {
	  var = variable_name_from_index(index);
	  sprintf(key, "s%d%s", id, var.c_str());
	  observation_header.push_back(key);
	}
      }
    }
    for(std::string value_key : pre_computed_keys) {
      observation_header.push_back(value_key);
    }
  }

  auto write_header_once() -> void {
    if(observer_header && !header_observed_flag) {
      build_header_once();
      outstream << "time";
      for(std::string _variable : observation_header) {
	outstream << observer_delimiter << _variable;
      }
      outstream << '\n';
      header_observed_flag = true;
    }
  }

  auto observer::operator() (state_type &variables, const double t) -> void {
    bool wrote=false;
    write_header_once();
    // reset and clear the stringstream before usage
    write_buffer.clear();
    write_buffer.str("");
    // load the stringstream
    write_buffer << std::setprecision(12) << t;
    for(unsigned id : pre_computed_indices) {
      write_buffer << observer_delimiter << (variables[id]);
    }
    for(std::string key : pre_computed_keys) {
      write_buffer << observer_delimiter << (value_map[key]);
    }
    write_buffer << '\n';
    // write the stringstream to file
    if((step_ctr >= write_ctr) && (write_this_interval==true)) {
      outstream << write_buffer.str();
      write_ctr = step_ctr + write_interval;
      wrote = true;
    }
    if((!wrote) && write_this_interval2){
      outstream << write_buffer.str();
      wrote = true;
    }
    ++step_ctr;
  }

  auto observe(std::string _variable) -> void {
    std::vector<unsigned> neuron_indices;
    std::vector<unsigned> synapse_indices;
    std::vector< std::string > neuron_keys;
    std::vector< std::string > synapse_keys;    
    neuron_indices = get_neuron_indices(_variable);
    synapse_indices = get_synapse_indices(_variable);
    neuron_keys = get_neuron_value_keys(_variable);
    synapse_keys = get_synapse_value_keys(_variable);
    if(neuron_indices.empty() && synapse_indices.empty() &&
       neuron_keys.empty() && synapse_keys.empty()) {
      std::cerr << "[insilico::configuration] Observer failed to find "<< _variable << ".\n";
      std::cerr << "****SIMULATION_FAILED*******";
      exit(EXIT_FAILURE);
    }
    if(!neuron_indices.empty()) {
      pre_computed_indices.insert(pre_computed_indices.end(),
				  neuron_indices.begin(),
				  neuron_indices.end());
    }
    else if(!neuron_keys.empty()) {
      pre_computed_keys.insert(pre_computed_keys.end(),
			       neuron_keys.begin(),
			       neuron_keys.end());
    }
    if(!synapse_indices.empty()) {
      pre_computed_indices.insert(pre_computed_indices.end(),
				  synapse_indices.begin(),
				  synapse_indices.end());
    }
    else if(!synapse_keys.empty()) {
      pre_computed_keys.insert(pre_computed_keys.end(),
			       synapse_keys.begin(),
			       synapse_keys.end());
    }
  }

  auto observe_neuron(unsigned id, std::string _variable) -> void {
    bool error_index = false;
    int neuron_index = get_neuron_index(id, _variable, error_index);
    std::string neuron_key = neuron_value_key(id, _variable);
    if(error_index && (neuron_key.compare("") == 0)) {
      std::cerr << "[insilico::configuration] Observer failed to find "
		<< _variable << " for Neuron " << id << ".\n";
      std::cerr << "********SIMULATION_FAILED********";
      exit(EXIT_FAILURE);
    }
    else if(!error_index) {
      pre_computed_indices.push_back(neuron_index);
    }
    else {
      pre_computed_keys.push_back(neuron_key);
    }
  }

  auto observe_neuron(std::vector<unsigned> ids, std::string _variable) -> void {
    for(unsigned id : ids) {
      observe_neuron(id, _variable);
    }
  }

  auto observe_synapse(unsigned id, std::string _variable) -> void {
    bool error_index = false;
    int synapse_index = get_synapse_index(id, _variable, error_index);
    std::string synapse_key = synapse_value_key(id, _variable);
    if(error_index && (synapse_key.compare("") == 0)) {
      std::cerr << "[insilico::configuration] Observer failed to find "
		<< _variable << " for Synapse " << id << ".\n";
      std::cerr << "*********SIMULATION_FAILED********";
      exit(EXIT_FAILURE);
    }
    else if(!error_index) {
      pre_computed_indices.push_back(synapse_index);
    }
    else {
      pre_computed_keys.push_back(synapse_key);
    }
  }

  auto observe_synapse(std::vector<unsigned> ids, std::string _variable) -> void {
    for(unsigned id : ids) {
      observe_synapse(id, _variable);
    }
  }
}
