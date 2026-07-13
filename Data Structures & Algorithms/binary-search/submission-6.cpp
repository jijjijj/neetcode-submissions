class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            // target is in [left, right]
            int mid = (right - left) / 2 + left;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid - 1;
        }

        if (right < 0 || right >= nums.size()) return -1;

        return nums[right] == target ? right : -1;
    }
};
