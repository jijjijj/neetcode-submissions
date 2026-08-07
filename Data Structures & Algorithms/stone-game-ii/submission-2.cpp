class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();

        std::vector<int> postfix(n + 1);
        for (int i = n - 1; i >= 0; --i)
            postfix[i] = piles[i] + postfix[i + 1];

        std::vector<std::vector<int>> dp(n + 1,
            std::vector<int>(n + 1));

        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n / 2; ++m) {
                if (i + 2 * m >= n) {
                    dp[i][m] = postfix[i];
                    continue;
                }

                int sum = 0;
                for (int x = 1; x <= std::min(2 * m, n - i); ++x) {
                    sum += piles[i + x - 1];
                    dp[i][m] = std::max(dp[i][m],
                        sum + postfix[i + x] - dp[i + x][std::max(x, m)]);
                }
            }
        }

        return dp[0][1];//dfs(piles, 0, 1).first;
    }

// private:
//     std::pair<int, int> dfs(const std::vector<int>& piles, int off, int m) {
//         const int n = piles.size();

//         if (off >= n) return {};

//         int max = 0;
//         int them = 0;
//         int sum = 0;
        
//         for (int x = off; x < std::min(off + m * 2, n); ++x) {
//             sum += piles[x];

//             const std::pair<int, int> res = dfs(piles, x + 1, std::max(x - off + 1, m));
//             if (res.second + sum > max) {
//                 max = res.second + sum;
//                 them = res.first;
//             }
//         }
//         return std::pair{ max, them };
//     }
};