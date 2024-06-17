#include <iostream>
#include <vector>

std::vector<std::string> CanReachNonDecreasingSegment(
    int n, int m, int k, std::vector<std::vector<int>> table,
    std::vector<std::pair<int, int>> range) {
  std::vector<std::vector<int>> non_decreasing_end(n, std::vector<int>(m));
  std::vector<int> dp(n);

  for (int j = 0; j < m; ++j) non_decreasing_end[n - 1][j] = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < m; ++j) {
      if (table[i][j] <= table[i + 1][j]) {
        non_decreasing_end[i][j] = non_decreasing_end[i + 1][j];
      } else
        non_decreasing_end[i][j] = i;
    }
  }

  dp[n - 1] = n - 1;
  for (int j = 0; j < m; ++j) {
    for (int i = n - 1; i >= 0; --i) {
      dp[i] = std::max(dp[i], non_decreasing_end[i][j]);
    }
  }

  std::vector<std::string> ans;
  for (int i = 0; i < k; ++i) {
    int l = range[i].first, r = range[i].second;
    l--;
    r--;
    if (dp[l] >= r)
      ans.push_back("Yes");
    else
      ans.push_back("No");
  }
  return ans;
}