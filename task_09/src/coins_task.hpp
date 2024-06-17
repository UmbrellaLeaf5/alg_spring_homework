#include <climits>
#include <vector>

size_t MinCoinsNumber(size_t sum, std::vector<size_t> coins) {
  std::vector<size_t> money(sum + 1, ULLONG_MAX);
  money[0] = 0;

  for (size_t i = 1; i <= sum; i++)
    for (size_t j : coins)
      if (j <= i) money[i] = std::min(money[i], money[i - j] + 1);

  return money[sum];
}