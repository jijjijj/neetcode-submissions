class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        const auto t = std::make_pair(target < nums.front(), target);
        while (l <= r) {
            const int mid = l + (r - l) / 2;
            const auto m = std::make_pair(nums[mid] < nums.front(), nums[mid]);
            if (m < t) {
                l = mid + 1;
            } else if (m > t) {
                r = mid - 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};
