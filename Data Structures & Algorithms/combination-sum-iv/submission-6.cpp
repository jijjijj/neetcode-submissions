class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, long long> dp;
        dp[0] = 1;

        for (int total = 1; total <= target; total++) {
            dp[total] = 0;
            for (int num : nums) {
                if (total >= num) {
                    dp[total] += dp[total - num];
                }
            }
        }
        return dp[target];
    }
};