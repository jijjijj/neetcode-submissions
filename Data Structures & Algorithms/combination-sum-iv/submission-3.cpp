class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        std::ranges::sort(nums);

        std::unordered_map<int, int> dp;

        dp[0] = 1;
        
        for (int i = 1; i <= target; ++i) {
            for (const int num : nums) {
                dp[i] += dp[i - num];
            }
        }

        return dp[target];
    }
};