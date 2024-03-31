#include <sstream>
#include <vector>
#include <algorithm>
#include "structures.hpp"

int main()
{
  using namespace doroshenko;
  using input_it_t = std::istream_iterator< DataStruct >;
  std::vector< DataStruct > data(input_it_t{ std::cin }, input_it_t{});

  std::sort(data.begin(), data.end(), compareStructs);

  using output_it_t = std::ostream_iterator< DataStruct >;
  std::copy(data.cbegin(), data.cend(), output_it_t{ std::cout, "\n" });
}
