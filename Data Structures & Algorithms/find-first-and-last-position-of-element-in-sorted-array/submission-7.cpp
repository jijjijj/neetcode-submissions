class Solution {
public:
    vector<int> searchRange(
        vector<int>& nums, int target) {
        std::vector<int> res{ -1, -1 };

        int index = bs(0, target, nums);

        if (index >= nums.size() ||
            nums[index] != target)
            return res;
        
        res[0] = index;
        res[1] = bs(index, target + 1, nums) - 1;

        return res;
    }

private:
    int bs(int l, int target, const std::vector<int>& nums) {
        int r = nums.size() - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};