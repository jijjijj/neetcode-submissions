class Solution {
public:
    int maxCoins(vector<int>& nums) {
        const int n = nums.size();

        std::vector<std::vector<int>> dp(n,
            std::vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                // std::cout << "i = " << i << ", j = " << j << std::endl;

                for (int k = j; k <= i; ++k) {
                    // std::cout << "refer to [" << j << ", " << (k - 1) << "] and ["
                    //     << (k + 1) << ", " << i << "]" << std::endl;
                    const int pre_n = (j > 0 ? nums[j - 1] : 1);
                    const int post_n = (i + 1 < n ? nums[i + 1] : 1);
                    const int pre_dp = (k > j ? dp[j][k - 1] : 0);
                    const int post_dp = (k < i ? dp[k + 1][i] : 0);

                    dp[j][i] = std::max({dp[j][i],
                        pre_n * nums[k] * post_n + pre_dp+post_dp
                        });
                }

                // std::cout << dp[j][i] << " ";
            }

            // std::cout << std::endl;
        }

        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         std::cout << dp[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }

        return dp[0][n - 1];
    }
};
