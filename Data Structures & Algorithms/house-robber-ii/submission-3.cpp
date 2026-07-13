class Solution {
public:
    int rob(vector<int>& nums) {
        return std::max(nums[0],
            std::max(dp(nums.begin(), nums.end() - 1),
                dp(nums.begin() + 1, nums.end())));
    }

private:
    int dp(std::vector<int>::iterator begin,
        std::vector<int>::iterator end) {
        int dp2 = 0;
        int dp1 = 0;
        for (auto it = begin; it != end; ++it) {
            const int tmp = std::max(*it + dp2, dp1);
            dp2 = dp1;
            dp1 = tmp;
        }

        return dp1;
    }
};
