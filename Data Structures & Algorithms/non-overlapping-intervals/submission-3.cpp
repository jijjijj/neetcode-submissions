#include <ranges>

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
                return a[1] < b[1];
            });

        std::vector<int> dp(intervals.size());
        dp[0] = 1;

        int max = 1;
        for (int i = 1; i < intervals.size(); ++i) {
            auto inter = intervals |
                std::views::transform([](const std::vector<int>& a) { return a[1]; });
            
            int ind = std::upper_bound(
                inter.begin(), inter.begin() + i, intervals[i][0]) - inter.begin();

            if (ind == 0) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = std::max(dp[i - 1], dp[ind - 1] + 1);
            }
            
            max = std::max(max, dp[i]);
        }

        return intervals.size() - dp.back();
    }
};
