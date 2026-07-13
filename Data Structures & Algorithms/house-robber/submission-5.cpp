class Solution {
public:
    int rob(vector<int>& nums) {
        return dfs(nums, nums.size() - 1);
    }

private:
    int dfs(const vector<int>& nums, int i) {
        if (i < 0) return 0;
        if (memo.contains(i)) return memo[i];

        memo[i] = std::max(nums[i] + dfs(nums, i - 2), dfs(nums, i - 1));

        return memo[i];
    }

    std::unordered_map<int, int> memo;
};
