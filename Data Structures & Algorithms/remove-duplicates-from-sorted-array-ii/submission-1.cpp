class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int to = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[to - 1] ||
                (i < 2 || nums[i] != nums[to - 2])) {
                nums[to++] = nums[i];
            }
        }
        return to;
    }
};