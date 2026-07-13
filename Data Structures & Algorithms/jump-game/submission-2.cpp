class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::vector<bool> dp(nums.size());
        dp.back() = true;

        for (int i = nums.size() - 2; i >= 0; --i) {
            const int most_far = std::min((int)nums.size(), i + nums[i] + 1);

            for (int j = i; j < most_far; ++j) {
                if (dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
