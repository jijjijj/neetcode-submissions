class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = 0;
        int i = nums.size() - 1;
        
        // 1 2 3, val = 1
        while (last < i) {
            if (nums[last] == val) {
                nums[last] = nums[i--];
            } else {
                ++last;
            }
        }

        return last + 1;
    }
};