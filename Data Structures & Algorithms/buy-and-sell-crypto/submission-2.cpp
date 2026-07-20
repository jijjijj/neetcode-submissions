class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int l = 0;
        int r = 1;

        int max = 0;

        while (r < nums.size()) {
            if (nums[l] < nums[r]) {
                max = std::max(max, nums[r] - nums[l]);
            } else {
                l = r;
            }
            ++r;
        }

        return max;
    }
};
