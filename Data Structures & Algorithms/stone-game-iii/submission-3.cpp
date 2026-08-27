class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        const int n = stones.size();

        std::vector<int> dp(4);

        for (int i = n - 1; i >= 0; --i) {
            int total = 0;

            dp[i % 4] = std::numeric_limits<int>::min();
            for (int x = i; x < std::min(n, i + 3); ++x) {
                total += stones[x];
                dp[i % 4] = std::max(dp[i % 4], total - dp[(x + 1) % 4]);
            }
        }

        return dp[0] < 0 ? "Bob" : (!dp[0] ? "Tie" : "Alice");
    }
};