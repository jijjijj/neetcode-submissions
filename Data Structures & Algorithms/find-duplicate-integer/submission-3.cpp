class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1;
        int r = nums.size() - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (count(nums, mid) <= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }

private:
    int count(std::vector<int>& nums, int mid) const {
        int c = 0;

        for (int n : nums) c += (n <= mid);

        return c;
    }
};
