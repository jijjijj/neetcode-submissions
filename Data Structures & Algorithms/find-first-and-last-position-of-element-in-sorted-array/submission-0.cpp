class Solution {
public:
    vector<int> searchRange(vector<int>& nums,
        int target) {
        int l = 0;
        int r = nums.size() - 1;

        std::vector<int> res{ -1, -1 };

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (l < 0)
            return res;
        
        res[0] = l;

        l = 0;
        r = nums.size() - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (r >= nums.size()) {
            res[0] = -1;
            return res;
        }

        res[1] = r;

        return res;
    }
};