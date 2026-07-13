class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> comb;

        dfs(nums, 0, target, comb, 0, result);

        return result;
    }

private:
    void dfs(const std::vector<int>& nums, int i, int target,
        std::vector<int>& comb, int curr,
        std::vector<std::vector<int>>& result) {
        if (curr > target) return;
        if (curr == target) {
            result.emplace_back(comb);
            return;
        }
        if (i == nums.size()) return;

        comb.emplace_back(nums[i]);
        dfs(nums, i, target, comb, curr + nums[i], result);
        comb.pop_back();

        dfs(nums, i + 1, target, comb, curr, result);
    }
};
