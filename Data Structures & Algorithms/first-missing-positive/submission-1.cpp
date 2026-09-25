class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ) {
            if (nums[i] <= 0) {
                ++i;
            } else if (nums[i] >= nums.size()) {
                ++i;
            } else if (nums[i] != i + 1 &&
                nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            } else {
                ++i;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) return i + 1;
        }

        return nums.size() + 1;
    }
};