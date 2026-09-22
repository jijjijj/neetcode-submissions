class Solution {
public:
    // backtracking + pruning + bitmask
    // dp bitmask
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        std::sort(nums.rbegin(), nums.rend());

        const int total = std::accumulate(nums.begin(), nums.end(), 0);
        if (total % k) return false;

        return can(0, nums, k, total / k);
    }

private:
    bool can(int cur, const vector<int>& nums, int k, int target) {
        if (k == 0) return true;
        if (target == cur) return can(0, nums, k - 1, target);

        for (int i = 0; i < nums.size(); ++i) {
            if ((visited & (1 << i)) || nums[i] + cur > target) continue;

            visited |= (1 << i);
            if (can(cur + nums[i], nums, k, target)) return true;
            visited ^= (1 << i);

            if (!cur) break;
        }
    }

    uint64_t visited{};
};