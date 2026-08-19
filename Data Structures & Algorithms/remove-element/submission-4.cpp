class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) nums[last++] = nums[i];
        }

        return last;
    }
};