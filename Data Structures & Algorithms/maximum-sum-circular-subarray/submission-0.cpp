class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max = std::numeric_limits<int>::min();
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cur < 0) {
                cur = 0;
            }
            cur += nums[i];
            max = std::max(cur, max);
        }

        int l = 0;
        int r = nums.size() - 1;
        cur = 0;

        while (l <= r) {
            if (nums[l] > nums[r]) {
                cur += nums[l];
                ++l;
            } else {
                cur += nums[r];
                --r;
            }

            max = std::max(cur, max);
        }

        return max;
    }
};