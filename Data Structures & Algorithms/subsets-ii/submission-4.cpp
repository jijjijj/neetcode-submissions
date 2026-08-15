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
        if (i >= nums.size()) {
            res.emplace_back(cur);
            return;
        }

        cur.emplace_back(nums[i]);
        dfs(nums, i + 1, cur);
        cur.pop_back();

        while (i + 1 < nums.size() &&
            nums[i + 1] == nums[i]) ++i;
        dfs(nums, i + 1, cur);
    }

    std::vector<std::vector<int>> res;
};
