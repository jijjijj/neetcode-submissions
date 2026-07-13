class Solution {
public:
    int maxProduct(vector<int>& nums) {
        std::vector<int> dp(nums.size());

        int max = -100000000;
        int curr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curr = curr ? curr * nums[i] : nums[i];
            dp[i] = std::max(i > 0 ? std::max(nums[i] * dp[i - 1], curr) : -10000000, nums[i]);
            max = std::max(std::max(dp[i], curr), max);
        }

        return max;
    }
};
