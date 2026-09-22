class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int n = nums.size();

        std::vector<int> suffixMax(n + 1);
        suffixMax.back() = std::numeric_limits<int>::min();

        const int total = std::accumulate(
            nums.begin(), nums.end(), 0);

        int current = 0;
        for (int i = n - 1; i >= 0; --i) {
            current += nums[i];
            suffixMax[i] = std::max(suffixMax[i + 1], current);
        }

        int prefix = 0;
        current = 0;
        int ans = nums[0];

        for (int i = 0; i < n; ++i) {
            current = std::max(current + nums[i], nums[i]);
            ans = std::max(current, ans);

            prefix += nums[i];
            if (i + 1 < n) {
                ans = std::max(ans, prefix + suffixMax[i + 1]);
            }
        }

        return ans;
    }
};