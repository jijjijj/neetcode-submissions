class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        int minn = nums[0];

        while (l <= r) {
            if (nums[l] < nums[r]) {
                return std::min(minn, nums[l]);
            }

            const int mid = l + (r - l) / 2;

            if (nums[mid] < nums[l]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }

            minn = std::min(minn, nums[mid]);
        }

        return minn;
    }
};
