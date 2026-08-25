class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        std::unordered_map<unsigned, unsigned> dp;

        dp[0] = 1;
        
        for (int i = 1; i <= target; ++i) {
            // bool brk = false;
            for (const int num : nums) {
                if (num > i) break;
                dp[i] += dp[i - num];
            }
        }

        return dp[target];
    }
};