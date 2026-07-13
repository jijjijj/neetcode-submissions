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
    void dfs(
        const std::vector<int>& nums,
        std::vector<std::vector<int>>& result,
        std::vector<int>& sub, int j) {
        result.emplace_back(sub);

        for (int i = j; i < nums.size(); ++i) {
            if (i > j && nums[i] == nums[i - 1]) continue;
            sub.emplace_back(nums[i]);
            dfs(nums, result, sub, i + 1);
            sub.pop_back();
        }
    }
};
