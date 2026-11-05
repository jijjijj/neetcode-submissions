class Solution {
    public int removeDuplicates(int[] nums) {
        int l = 2, c = 0;
        for (int r = 2; r < nums.length; r++) {
            if (nums[r] != nums[r - 2 - c]) {
                nums[l++] = nums[r];
            } else {
                c++;
            }
        }
        return l;
    }
}