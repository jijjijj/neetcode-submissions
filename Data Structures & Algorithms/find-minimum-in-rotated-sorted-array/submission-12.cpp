class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        int min = nums[0];
        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (nums[mid] > nums.back()) {
                l = mid + 1;
            } else {
                min = nums[mid];
                r = mid - 1;
            }
        }

        return min;
    }
};
