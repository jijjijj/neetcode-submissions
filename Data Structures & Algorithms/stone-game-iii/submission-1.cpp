class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        const int n = stones.size();

        std::vector<int> dp(n + 1,
            std::numeric_limits<int>::min());
        dp.back() = 0;

        for (int i = n - 1; i >= 0; --i) {
            int total = 0;

            for (int x = i; x < std::min(n, i + 3); ++x) {
                total += stones[x];
                dp[i] = std::max(dp[i], total - dp[x + 1]);
            }
        }

        return dp[0] < 0 ? "Bob" : (!dp[0] ? "Tie" : "Alice");
    }
};