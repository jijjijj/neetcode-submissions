class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp;

        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (dp.empty() || dp.back() < nums[i]) {
                dp.emplace_back(nums[i]);
                ++result;
                continue;
            }

            const int ind = std::ranges::lower_bound(dp, nums[i]) - dp.begin();
            dp[ind] = nums[i];
        }

        return result;
    }
};
