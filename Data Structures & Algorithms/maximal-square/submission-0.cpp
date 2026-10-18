class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int h = matrix.size();
        const int w = matrix[0].size();

        std::vector<std::vector<int>> prefix(h + 1,
            std::vector<int>(w + 1));

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                prefix[y + 1][x + 1] =
                    (matrix[y][x] - '0');
                prefix[y + 1][x + 1] += prefix[y][x + 1] +
                    prefix[y + 1][x] - prefix[y][x];
            }
        }

        std::vector<std::vector<int>> dp(h + 1,
            std::vector<int>(w + 1));
        int max = 0;

        for (int y = h - 1; y >= 0; --y) {
            for (int x = w - 1; x >= 0; --x) {
                dp[y][x] = matrix[y][x] - '0';
                if (!dp[y][x]) {
                // std::cout << "0 ";
                    continue;}
                
                for (int k = dp[y + 1][x + 1] + 1; k >= 2; --k) {
                    if (y + k > h || x + k > w) continue;

                    if (prefix[y + k][x + k] + prefix[y][x] -
                        prefix[y + k][x] - prefix[y][x + k] == k * k) {

                        dp[y][x] = k;
                        break;
                    }
                } 

                max = std::max(dp[y][x] * dp[y][x], max);
                // std::cout << dp[y][x] << " ";
            }
            // std::cout << std::endl;
        }

        return max;
    }
};