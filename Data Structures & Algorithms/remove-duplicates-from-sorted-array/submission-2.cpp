class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int l = 0;
        // int r = 0;
        while (l < nums.size()) {
            if (!l || nums[l - 1] != nums[l]) {
                nums[k++] = nums[l];
            }
            ++l;
        }

        return k;
    }
};