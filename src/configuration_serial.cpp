#include "include/configuration_serial.hpp"

namespace newinsilico

{

  void initialize(int argc, char **argv) {
    extern std::ofstream outstream;
    bool repeat[5] = {false, false, false, false, false};
    std::string sargv, output_file, neuron_file, synapse_file,
      external_current_file, dynamic_params_file;
    std::string error_msg = "[newinsilico::initialize]"
      " Supply of file more than once not allowed.\n";
    std::string usage_error_msg = "[newinsilico::initialize] USAGE: ";
    usage_error_msg += argv[0];
    usage_error_msg += " -o <output_file.csv> -n <neuron_file.isf> "
      "-s <synapse_file.isf> -e <external_file.isfc> -d <dynamic_params.isfd>\n"
      "\n    Options:\n"
      "\t-o   Output file\n"
      "\t-n   Neuron configuration file\n"
      "\t-s   Synapse configuration file (optional)\n"
      "\t-e   External current configuration file (optional)\n"
      "\t-d   Dynamic parameters configuration file (optional)\n\n";

    for(int i=1; i < argc; ++i) { sargv += argv[i]; sargv += ' '; }
    std::vector<std::string> cmds = split(sargv, ' ');
    if(cmds.size() < 4 || cmds.size() > 10) {
      std::cerr << usage_error_msg; exit(0);
    }

    std::cerr << "[newinsilico::initialize]"
      "SUCCESS: Initializing with following parameters:\n";
    for(unsigned iter = 0; iter < cmds.size(); iter+=2) {
      std::string cmd = cmds[iter];
      switch(cmd.at(1)) {
      case 'o':
        if(repeat[0]) { std::cerr<<error_msg<<'\n'<<usage_error_msg; exit(1); }
        output_file = cmds[iter+1];
        std::cerr << "Output file: " << output_file << '\n';
        repeat[0] = true;
        break;
      case 'n':
        if(repeat[1]) { std::cerr<<error_msg<<'\n'<<usage_error_msg; exit(1); }
        neuron_file = cmds[iter+1];
        std::cerr << "Neuron file: " << neuron_file << '\n';
        repeat[1] = true;
        break;
      case 's':
        if(repeat[2]) { std::cerr<<error_msg<<'\n'<<usage_error_msg; exit(1); }
        synapse_file = cmds[iter+1];
        std::cerr << "Synapse file: " << synapse_file << '\n';
        repeat[2] = true;
        break;
      case 'e':
        if(repeat[3]) { std::cerr<<error_msg<<'\n'<<usage_error_msg; exit(1); }
        external_current_file = cmds[iter+1];
        std::cerr << "External current file: " << external_current_file << '\n';
        repeat[3] = true;
        break;
      case 'd':
        if(repeat[4]) { std::cerr<<error_msg<<'\n'<<usage_error_msg; exit(1); }
        dynamic_params_file = cmds[iter+1];
        std::cerr << "Dynamic parameters file: " << dynamic_params_file << '\n';
        repeat[4] = true;
        break;
      default:
        std::cerr << "Default error: Unknown argument " << cmd << std::endl;
        std::cerr << usage_error_msg; exit(0);
      }
    }
    if(repeat[0]) { outstream.open(output_file, std::ios::out); }
    else {
      std::cerr << "[newinsilico::initialize]"
        " Output file is required.\n";
      exit(1);
    }
    if(repeat[2]) { read_neuron_synapse(neuron_file, synapse_file); }
    else if(repeat[1]) { read_neuron_synapse(neuron_file); }
    else {
      std::cerr << "[insilico::configuration::initialize]"
        " Neuron configuration file is required.\n";
      exit(1);
    }
    if(repeat[3]) { read_external_current(external_current_file); }
    if(repeat[4]) { read_dynamic_params(dynamic_params_file); }
    std::cerr << "[newinsilico::read]"
      " SUCCESS: Input file read complete." << '\n';
  }

  void finalize() {
    std::ofstream outstream;
    outstream.close();
    std::cerr << "[newinsilico::finalize]"
      " SUCCESS: Releasing resources."<<'\n';
  
  }
}
