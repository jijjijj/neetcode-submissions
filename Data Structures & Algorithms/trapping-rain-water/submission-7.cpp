class Solution {
public:
    int trap(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        int max = 0;

        // while (l <= r && !nums[l]) ++l;
        // while (l <= r && !nums[r]) --r;

        int maxl = 0;
        int maxr = 0;

        while (l <= r) {
            if (nums[l] < nums[r]) {
                maxl = std::max(nums[l], maxl);
                max += std::max(maxl - nums[l], 0);
                ++l;
            } else {
                maxr = std::max(nums[r], maxr);
                max += std::max(maxr - nums[r], 0);
                --r;
            }
        }

        return max;
    }
};
