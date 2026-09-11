class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return std::max(dp(nums, 0), dp(nums, 1));
    }

private:
    int dp(const vector<int>& nums, int i) {
        std::vector<int> d(nums.size() + 2);
        for (int j = nums.size() - i - 1; j >= 0; --j) {
            d[j] = std::max(nums[j] + d[j + 2], d[j + 1]);
        }
        return d[1 - i];
    }
};
