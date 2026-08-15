class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        // res.push_back({}); // seed

        std::vector<int> cur;
        dfs(nums, res, 0, cur);

        return res;
    }

private:
    void dfs(
        const vector<int>& nums,
        std::vector<std::vector<int>>& res,
        int i, std::vector<int>& cur) {
        if (i >= nums.size()) {
            res.emplace_back(cur);
            return;
        }

        cur.emplace_back(nums[i]);
        dfs(nums, res, i + 1, cur);
        cur.pop_back();

        dfs(nums, res, i + 1, cur);
    }
};
