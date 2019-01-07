#include "include/helper_file.hpp"

// check if the file is present and is permitted to open
bool newinsilico::file_check(const std::ifstream &stream, const std::string &filename) {
  if((!filename.empty()) && stream.is_open() == false) {
    std::cerr<<"[insilico::core::helper::file] Input file "<< filename
             <<" that does not exist or cannot be opened.\n";
    return false;
  }
  return true;
}
