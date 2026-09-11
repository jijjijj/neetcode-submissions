class Solution {
public:
    int rob(vector<int>& nums) {
        return std::max({
            dp(nums, 0, nums.size() - 1),
            dp(nums, 1, nums.size()),
            nums[0]
        });
    }

private:
    int dp(const vector<int>& nums, int start, int end) {
        int last1 = 0;
        int last2 = 0;
        for (int j = start; j < end; ++j) {
            const int t = std::max(nums[j] + last2, last1);
            last2 = last1;
            last1 = t;
        }
        return last1;
    }
};
