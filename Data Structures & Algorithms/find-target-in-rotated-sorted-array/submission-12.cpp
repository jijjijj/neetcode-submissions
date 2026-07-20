class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;

if (nums[mid] <= nums[r]) {              // right half [mid, r] is sorted
    if (target > nums[mid] && target <= nums[r]) l = mid + 1;
    else r = mid - 1;
} else {                                  // left half [l, mid] is sorted
    if (target >= nums[l] && target < nums[mid]) r = mid - 1;
    else l = mid + 1;
}

            if (nums[mid] == target) return mid;
        }

        return -1;
    }
};
