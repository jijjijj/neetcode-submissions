class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(nums, 0);

        return res;
    }

private:
    void dfs(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            res.emplace_back(nums);
            return;
        }

        std::unordered_set<int> used;
        for (int j = i; j < nums.size(); ++j) {
            if (used.contains(nums[j])) continue;
            used.emplace(nums[j]);
            std::swap(nums[i], nums[j]);
            dfs(nums, i + 1);
            std::swap(nums[i], nums[j]);
        }
    }

    std::vector<std::vector<int>> res;
};