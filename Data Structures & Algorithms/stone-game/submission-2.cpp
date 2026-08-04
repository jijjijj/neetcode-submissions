class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        const int n = piles.size();
        const int sum = std::accumulate(piles.begin(), piles.end(), 0);

        std::vector<std::vector<int>> dp(n + 1,
            std::vector<int>(n + 1));

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++len) {
                const int j = i + len - 1;
                const bool alice = !((i + j) % 2);
                dp[i][j] = std::max(
                    dp[i + 1][j] + (alice ? piles[i] : 0),
                    j > 0 ? (dp[i][j - 1] + (alice ? piles[j] : 0)) : 0);
            }
        }


        return dp[0][n - 1] > (sum / 2);
    }

private:
    int f(vector<int>& piles, int i, int j, int alice) {
        if (i > j) return 0;

        return std::max(f(piles, i + 1, j, !alice) + (alice ? piles[i] : 0),
            f(piles, i, j - 1, !alice) + (alice ? piles[j] : 0));
    }
};