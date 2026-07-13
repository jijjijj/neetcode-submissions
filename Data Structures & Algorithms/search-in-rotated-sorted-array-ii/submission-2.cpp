class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r && nums[l] == nums[r]) {
            ++l;
            --r;
        }

        if (l > r) return false;

        const int front = nums[l];
        const auto t = std::make_pair(target < front, target);

        while (l <= r) {
            const int mid = l + (r - l) / 2;
            const auto m = std::make_pair(nums[mid] < front,
                nums[mid]);
                
            if (nums[mid] == target) return true;
            else if (m < t) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};