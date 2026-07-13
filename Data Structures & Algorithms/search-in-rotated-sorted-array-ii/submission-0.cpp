class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        const auto t = std::make_pair(target < nums.front(),
            std::make_pair(target, 0));

        while (l <= r) {
            const int mid = l + (r - l) / 2;
            const auto m = std::make_pair(nums[mid] < nums.front(),
                std::make_pair(nums[mid], mid));
                
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