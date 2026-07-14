class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::ranges::sort(nums);

        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            const int sum = nums[l] + nums[r];
            if (sum > target) {
                --r;
            } else if (sum < target) {
                ++l;
            } else {
                return { l, r };
            }
        }

        return { -1, -1 };
    }
};
