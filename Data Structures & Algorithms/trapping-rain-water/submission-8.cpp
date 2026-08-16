class Solution {
public:
    int trap(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        const int n = nums.size();
        std::vector<int> left(n, 0);
        std::vector<int> right(n, 0);

        for (int i = 0; i < n; ++i) {
            left[i] = std::max(nums[i], i ? left[i - 1] : 0);
        }

        for (int i = n - 1; i >= 0; --i) {
            right[i] = std::max(nums[i],
                i < n - 1 ? right[i + 1] : 0);
        }

        int area = 0;

        // while (l <= r && !nums[l]) ++l;
        // while (l <= r && !nums[r]) --r;

        int maxl = 0;
        int maxr = 0;

        for (int i = 0; i < n; ++i) {
            area += std::max(0,
                std::min(left[i], right[i]) - nums[i]);
        }

        return area;
    }
};
