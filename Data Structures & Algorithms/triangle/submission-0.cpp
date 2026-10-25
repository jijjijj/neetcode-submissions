class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int n = triangle.size();
        std::vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            std::vector<int> dp2 = dp;

            for (int j = 0; j <= i; ++j) {
                dp2[j] = triangle[i][j] + std::min(dp[j], dp[j + 1]);
            }

            dp = std::move(dp2);
        }

        return dp.front();
    }
};