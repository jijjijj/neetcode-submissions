class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        std::unordered_map<unsigned, unsigned> dp;

        dp[0] = 1;
        
        for (int i = 0; i <= target; ++i) {
            // bool brk = false;
            for (const int num : nums) {
                if (num + i > target) break;
                dp[i + num] += dp[i];
            }
        }

        return dp[target];
    }
};