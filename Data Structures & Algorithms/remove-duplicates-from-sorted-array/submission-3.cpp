class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int r = 0;
        while (r < nums.size()) {
            nums[l++] = nums[r++];
            while (r < nums.size() && (!r || nums[r] == nums[r - 1])) ++r;
        }

        return l;
    }
};