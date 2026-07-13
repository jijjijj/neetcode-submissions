class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            const int m = l + (r - l) / 2;

            if (nums[m] == target)
                return m;
            else if (nums[m] >= nums[l]) {
                // left is sorted
                if (target >= nums[m]) {
                    l = m + 1;
                } else if (target >= nums[l]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                // right is sorted
                if (target <= nums[m]) {
                    r = m - 1;
                } else if (target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};
