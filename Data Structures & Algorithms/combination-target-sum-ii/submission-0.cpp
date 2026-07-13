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

        if (i == nums.size() || curr > target) return;

        comb.emplace_back(nums[i]);
        dfs(nums, i + 1, comb, result, target, curr + nums[i]);
        comb.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;

        dfs(nums, i + 1, comb, result, target, curr);
    }
};
