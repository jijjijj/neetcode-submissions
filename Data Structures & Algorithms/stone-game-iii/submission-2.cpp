class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        const int n = stones.size();

        std::vector<int> dp(4);

        for (int i = n - 1; i >= 0; --i) {
            int total = 0;

            dp[0] = std::numeric_limits<int>::min();
            for (int x = 1; x <= std::min(n - i, 3); ++x) {
                total += stones[i + x - 1];
                dp[0] = std::max(dp[0], total - dp[(x % 4)]);
            }

            for (int j = 3; j >= 1; --j) dp[j] = dp[j - 1];
        }

        return dp[0] < 0 ? "Bob" : (!dp[0] ? "Tie" : "Alice");
    }
};