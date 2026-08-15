class Solution {
public:
    // iter.
    // swap-based backtracking
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);

        return res;
    }

private:
    void dfs(std::vector<int>& nums, int i) {
        if (i == nums.size()) {
            res.emplace_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); ++j) {
            std::swap(nums[j], nums[i]);
            dfs(nums, i + 1);
            std::swap(nums[j], nums[i]);
        }
    }

    std::vector<std::vector<int>> res;
};
