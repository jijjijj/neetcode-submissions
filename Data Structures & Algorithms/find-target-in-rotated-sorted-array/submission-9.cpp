class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        int pivot = r;
        if (nums[0] >= target) {
            l = pivot;
            r = nums.size() - 1;
        } else {
            l = 0;
            r = pivot - 1;
        }

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};
