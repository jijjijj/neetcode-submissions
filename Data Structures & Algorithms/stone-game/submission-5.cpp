class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        const int n = piles.size();
        const int sum = std::accumulate(
            piles.begin(), piles.end(), 0);

        std::vector<int> dp(n + 1);

        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                // [j, i]
                const bool alice = (i + j) & 1;
                const int left = alice ? piles[j] : 0;
                const int right = alice ? piles[i] : 0;

                if (i == j) {
                    dp[j] = left;
                } else {
                    dp[j] = std::max(
                        dp[j + 1] + left,
                        dp[j] + right);
                }
            }
        }

        return dp.front() > (sum / 2);
    }
};