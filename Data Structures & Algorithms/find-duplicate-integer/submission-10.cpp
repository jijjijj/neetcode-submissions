class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int index = nums[i];
            if (index < 0) index = -index;
            if (nums[index - 1] < 0) return index;
            nums[index - 1] *= -1;
        }

        return -1;
    }
};
