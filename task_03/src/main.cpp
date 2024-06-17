// my libs:
#include "days_before_warming.hpp"

// std usings:
using std::cout, std::cin, std::endl;

int main() {
  std::vector<Temperature> vec{1,  2,  3, 4,  4,  3,  2,  1, 0,
                               -1, -5, 8, 31, -9, 58, 36, 5};
  cout << vec << endl;

  cout << DaysBeforeWarmingSillyLooping(vec) << endl;
  cout << endl;

  cout << DaysBeforeWarmingSmarterLooping(vec) << endl;
  cout << endl;

  cout << DaysBeforeWarmingStackLooping(vec) << endl;
  cout << endl;
}
