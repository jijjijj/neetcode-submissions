class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::ranges::sort(nums);
        std::vector<int> cur;

        dfs(nums, 0, cur);

        return res;
    }

private:
    void dfs(const std::vector<int>& nums,
        int i, std::vector<int>& cur) {
        res.emplace_back(cur);

        for (int j = i; j < nums.size(); ++j) {
            if (j > i && nums[j - 1] == nums[j]) continue;

            cur.emplace_back(nums[j]);
            dfs(nums, j + 1, cur);
            cur.pop_back();
        }
    }

    std::vector<std::vector<int>> res;
};
