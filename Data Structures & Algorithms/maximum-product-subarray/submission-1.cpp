class Solution {
public:
    int maxProduct(vector<int>& nums) {
        std::vector<int> dp(nums.size());

        int max = -100000000;
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = std::max(i > 0 ? nums[i] * dp[i - 1] : -10000000, nums[i]);
            max = std::max(dp[i], max);
        }

        return max;
    }
};
