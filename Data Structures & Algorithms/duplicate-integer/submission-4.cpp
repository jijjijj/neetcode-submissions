class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::ranges::sort(nums);

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) return true;
        }

        return false;
    }
};