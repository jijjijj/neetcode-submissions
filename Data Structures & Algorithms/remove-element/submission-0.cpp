class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = nums.size() - 1;

        while (last >= 0 && nums[last] == val) --last;

        for (int i = 0; i <= last; ++i) {
            if (nums[i] == val) {
                std::swap(nums[i], nums[last--]);
            }
        }

        return last + 1;
    }
};