#include "include/helper_floating_comp.hpp"
#include "include/data.hpp"

namespace newinsilico
{  
  auto isequal(const double first, const double second) -> bool {
    if(std::abs(first - second) <= (__acceptable_error * std::abs(first))) {
      return true;
    }
    return false;
  }
}
