class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        int mink = nums[0];

        while (l <= r) {
            if (nums[l] <= nums[r]) {
                mink = std::min(mink, nums[l]);
                break;
            }

            const int mid = l + (r - l) / 2;
            mink = std::min(mink, nums[mid]);

            if (nums[l] <= nums[mid]) {
                // left is sorted
                l = mid + 1;
            } else {
                // right is sorted
                r = mid;
            }
        }

        return mink;
    }
};
