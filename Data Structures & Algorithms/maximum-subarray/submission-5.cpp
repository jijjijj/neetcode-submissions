class Solution {
public:
    // dp, dp space-optimized, divide&conquer
    int maxSubArray(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }

private:
    int dfs(const std::vector<int>& nums,
        int l, int r) const {
        if (l > r)
            return std::numeric_limits<int>::min();

        const int mid = l + (r - l) / 2;

        int left = 0;
        int cur = 0;

        for (int i = mid - 1; i >= l; --i) {
            cur += nums[i];
            left = std::max(left, cur);
        }

        int right = 0;
        cur = 0;
        for (int i = mid + 1; i <= r; ++i) {
            cur += nums[i];
            right = std::max(right, cur);
        }

        return std::max({left + right + nums[mid],
            dfs(nums, l, mid - 1), dfs(nums, mid + 1, r)});
    }
};
