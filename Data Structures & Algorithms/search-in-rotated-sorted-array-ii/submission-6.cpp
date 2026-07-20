class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l < r && nums[l] == nums[r]) ++l;

        const auto t = std::pair{ target <= nums.back(), target };

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            const auto m = std::pair{
                nums[mid] <= nums.back(), nums[mid] };
            if (m < t) {
                l = mid + 1;
            } else if (m > t) {
                r = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};