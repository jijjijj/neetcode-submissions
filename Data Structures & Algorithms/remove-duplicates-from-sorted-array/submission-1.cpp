class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int l = 0;
        // int r = 0;
        while (l < nums.size()) {
            if (l > 0 && nums[l - 1] == nums[l]) {
                ++l;
                continue;
            }
            nums[k++] = nums[l++];
        }

        return k;
    }
};