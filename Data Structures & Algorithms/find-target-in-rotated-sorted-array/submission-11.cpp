class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (nums[mid] <= nums[r]) {
                if (target >= nums[l]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (target >= nums[l]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (nums[mid] == target) return mid;
        }

        return -1;
    }
};
