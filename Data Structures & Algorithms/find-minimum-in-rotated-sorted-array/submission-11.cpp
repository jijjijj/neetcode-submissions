class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            // if (nums[l] < nums[r]) return nums[l];

            const int mid = l + (r - l) / 2;

            if (nums[l] <= nums[mid]) {
                // left is sorted
                l = mid + 1;
            } else {
                // right is sorted
                r = mid;
            }
        }

        return nums[l];
    }
};
