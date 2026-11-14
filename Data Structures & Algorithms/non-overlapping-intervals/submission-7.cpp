class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
            [](const auto& a, const auto& b) {
                // if (a[0] != b[0]) return a[0] < b[0];

                return a[1] < b[1];
            });
        
        const int n = intervals.size();
        std::vector<int> dp(n);
        dp[0] = 1;

        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1];

            int l = 0;
            int r = i - 1;

            while (l <= r) {
                const int mid = l + (r - l) / 2;

                if (intervals[i][0] >= intervals[mid][1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (r >= 0) dp[i] = std::max(dp[i], 1 + dp[r]);
        }
        
        return n - dp.back();
    }
};