class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return bs(nums, 0, nums.size() - 1);
    }

private:
    int bs(const vector<int>& nums, int l, int r) {
        if (l == r) return l;

        const int mid = l + (r - l) / 2;

        if (nums[mid] > nums[mid + 1]) {
            return bs(nums, l, mid);
        }

        return bs(nums, mid + 1, r);
    }
};