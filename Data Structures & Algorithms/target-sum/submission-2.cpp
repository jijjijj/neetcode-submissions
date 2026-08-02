class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int n = nums.size();

        std::unordered_map<int, int> dp;
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            std::unordered_map<int, int> dp_;

            for (auto& p : dp) {
                const int num = nums[i];
                dp_[p.first - num] += p.second;
                dp_[p.first + num] += p.second;
            }

            dp = std::move(dp_);
        }

        return dp[target];
    }
};
