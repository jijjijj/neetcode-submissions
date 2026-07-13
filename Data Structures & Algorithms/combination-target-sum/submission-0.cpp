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

        for (int j = i; j < nums.size(); ++j) {
            comb.emplace_back(nums[j]);
            dfs(nums, j, target, comb, curr + nums[j], result);
            comb.pop_back();
        }
        
        // dfs(nums, i, target, comb, curr, result);
        // dfs(nums, i + 1, target, comb, curr, result);
    }
};
