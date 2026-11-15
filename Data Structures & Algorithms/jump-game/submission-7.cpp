class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();

        std::vector<bool> dp(n);
        dp[n - 1] = true;

        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j <= std::min(n - 1, i + nums[i]); ++j) {
                if (dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
