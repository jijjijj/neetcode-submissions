class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        int res = nums[0];
        while (l <= r) {
            if (nums[l] <= nums[r]) {
                return std::min(res, nums[l]);
            }

            const int mid = l + (r - l) / 2;

            res = std::min(res, nums[mid]);
            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};
