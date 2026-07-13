class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
                return a[1] < b[1];
            });

        std::vector<int> dp(intervals.size());
        int max = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (intervals[j][1] <= intervals[i][0]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            max = std::max(max, dp[i]);
        }

        return intervals.size() - max;
    }
};
