class Solution {
public:
    // +backtracking + pruning + bitmask
    // dp bitmask
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const int total = std::accumulate(nums.begin(), nums.end(), 0);
        if (total % k) return false;
        const int target = total / k;

        std::sort(nums.rbegin(), nums.rend());

        const int n = nums.size();
        const int max_mask = 1 << n;
        std::vector<int> dp(max_mask, -1);
        dp[0] = 0;

        for (int i = 0; i < max_mask; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i | (1 << j)] != -1 ||
                    dp[i] + nums[j] > target) continue;

                dp[i | (1 << j)] = (dp[i] + nums[j]) % target;
            }
        }

        return !dp.back();
    }
};