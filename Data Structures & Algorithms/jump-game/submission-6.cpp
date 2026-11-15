class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::vector<bool> dp(nums.size());
        dp[0] = true;

        for (int i = 0; i < nums.size(); ++i) {
            if (!dp[i]) break;

            for (int j = i; j <= i + nums[i]; ++j)
                dp[j] = true;
        }

        return dp.back();
    }
};
