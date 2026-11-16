class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return div(0, nums.size() - 1, nums);
    }

private:
    int div(int l, int r, const std::vector<int>& nums) const {
        if (l > r) return std::numeric_limits<int>::min();

        const int mid = l + (r - l) / 2;

        int cur = 0;
        int left = 0;
        int i = mid - 1;
        while (i >= l) {
            cur += nums[i--];
            left = std::max(cur, left);
        }

        i = mid + 1;
        int right = 0;
        cur = 0;
        while (i <= r) {
            cur += nums[i++];
            right = std::max(cur, right);
        }

        return std::max({
            div(l, mid - 1, nums),
            div(mid + 1, r, nums),
            left + right + nums[mid]
        });
    }
};
