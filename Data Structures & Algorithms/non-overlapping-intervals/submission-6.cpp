class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
            [](const auto& a, const auto& b) {
                // if (a[0] != b[0]) return a[0] < b[0];

                return a[0] < b[0];
            });
        
        const int n = intervals.size();
        std::vector<int> dp(n);
        dp[0] = 1;

        for (int i = 1; i < n; ++i) {
            dp[i] = 1;

            for (int j = 0; j < i; ++j) {
                if (intervals[i][0] >= intervals[j][1]) {
                    dp[i] = std::max(dp[i], 1 + dp[j]);
                }
            }
        }
        
        return n - dp.back();
    }
};
