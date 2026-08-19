class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = nums.size() - 1;

        for (int i = 0; i <= last; ++i) {
            while (last >= 0 && nums[last] == val) --last;

            if (i <= last && nums[i] == val) {
                std::swap(nums[i], nums[last--]);
            }
        }

        return last + 1;
    }
};