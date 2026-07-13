class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::ranges::sort(candidates);

        std::vector<std::vector<int>> result;
        std::vector<int> comb;

        dfs(candidates, 0, comb, result, target, 0);

        return result;
    }

private:
    void dfs(const std::vector<int>& nums, int i, std::vector<int>& comb,
        std::vector<std::vector<int>>& result, int target, int curr) {
        if (curr == target) {
            result.emplace_back(comb);
            return;
        }

        if (i == nums.size()) return;

        for (int j = i; j < nums.size(); ++j) {
            if (j > i && nums[j] == nums[j - 1]) continue;
            
            comb.emplace_back(nums[j]);
            dfs(nums, j + 1, comb, result, target, curr + nums[j]);
            comb.pop_back();
        }
    }
};
