class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int h = matrix.size();
        const int w = matrix[0].size();

        std::vector<int> dp(w + 1);
        int max = 0;
        int last = 0;

        for (int y = h - 1; y >= 0; --y) {
            for (int x = w - 1; x >= 0; --x) {
                const int tmp = dp[x];
                dp[x] = matrix[y][x] - '0';
               
                if (dp[x]) {
                    dp[x] = std::min({ tmp, last, dp[x + 1]}) + 1;
                }

                max = std::max(dp[x], max);
                last = tmp;
            }
        }

        return max * max;
    }
};