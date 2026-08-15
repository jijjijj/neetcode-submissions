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

        cur.emplace_back(nums[i]);
        dfs(left - nums[i], cur, nums, i + 1);
        cur.pop_back();

        while (i + 1 < nums.size() &&
            nums[i + 1] == nums[i]) ++i;
        dfs(left, cur, nums, i + 1);
    }

    std::vector<std::vector<int>> res;
};
