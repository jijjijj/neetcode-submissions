class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::ranges::sort(nums);

        dfs(nums, 0);

        return res;
    }

private:
    void dfs(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            res.emplace_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); ++j) {
            if (j > i && nums[j] == nums[i]) continue;

            std::swap(nums[i], nums[j]);
            dfs(nums, i + 1);
            std::swap(nums[i], nums[j]);
        }
    }

    std::vector<std::vector<int>> res;
};