class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;

        std::vector<int> subset;
        dfs(nums, 0, subset, result);

        return result;
    }

private:
    void dfs(const std::vector<int>& nums, int i, std::vector<int>& subset,
        std::vector<std::vector<int>>& result) {
        if (i == nums.size()) {
            result.emplace_back(subset);
            return;
        }

        subset.emplace_back(nums[i]);
        dfs(nums, i + 1, subset, result);
        subset.pop_back();
        dfs(nums, i + 1, subset, result);
    }
};
