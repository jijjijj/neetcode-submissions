class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates,
        int target) {
        std::ranges::sort(candidates);

        std::vector<int> cur;

        dfs(target, cur, candidates, 0);

        return res;
    }

private:
    void dfs(int left, std::vector<int>& cur,
        const vector<int>& nums, int i) {
        if (!left) {
            res.emplace_back(cur);
            return;
        }
        if (i >= nums.size()) return;

        for (int j = i; j < nums.size(); ++j) {
            if (left - nums[j] < 0) return;
            if (j > i && nums[j - 1] == nums[j]) continue;

            cur.emplace_back(nums[j]);
            dfs(left - nums[j], cur, nums, j + 1);
            cur.pop_back();
        }
    }

    std::vector<std::vector<int>> res;
};
