class Solution {
public:
    // dp
    // +sliding window
    // +iteration
    int maxTurbulenceSize(vector<int>& arr) {
        std::vector<std::vector<int>> dp(arr.size(),
            std::vector<int>(2, 1));

        int max = 1;

        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1]) {
                dp[i][0] = 1 + dp[i - 1][1];
            } else if (arr[i] < arr[i - 1]) {
                dp[i][1] = 1 + dp[i - 1][0];
            }

            max = std::max({ max, dp[i][0], dp[i][1] });
        }

        return max;
    }
};