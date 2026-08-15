class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::ranges::sort(nums);

        std::vector<std::vector<int>> res;
        std::vector<int> cur;

        dfs(res, nums, 0, target, cur);

        return res;
    }

private:
    void dfs(
        std::vector<std::vector<int>>& res,
        const vector<int>& nums, int i,
        int left, std::vector<int>& cur) {
        if (i >= nums.size()) return;
        if (!left) {
            res.emplace_back(cur);
            return;
        }

        for (; i < nums.size(); ++i) {
            if (left - nums[i] < 0) return;

            cur.emplace_back(nums[i]);
            dfs(res, nums, i, left - nums[i], cur);
            cur.pop_back();
        }

        // dfs(res, nums, i + 1, left, cur);
    }
};
