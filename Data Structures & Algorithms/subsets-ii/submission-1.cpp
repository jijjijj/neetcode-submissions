class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::ranges::sort(nums);

        std::vector<std::vector<int>> result;
        std::vector<int> sub;

        dfs(nums, result, sub, 0);

        return result;
    }

private:
    void dfs(const std::vector<int>& nums,
        std::vector<std::vector<int>>& result,
        std::vector<int>& subset, int i) {
        if (i == nums.size()) {
            result.emplace_back(subset);
            return;
        }

        subset.emplace_back(nums[i]);
        dfs(nums, result, subset, i + 1);
        subset.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;

        dfs(nums, result, subset, i + 1);
    }
};
