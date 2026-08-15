class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<bool> vis(nums.size());
        std::vector<int> cur;

        dfs(nums, 0, vis, cur);

        return res;
    }

private:
    void dfs(const std::vector<int>& nums,
        int i, std::vector<bool>& vis,
        std::vector<int>& cur) {
        if (cur.size() == nums.size()) {
            res.emplace_back(cur);
            return;
        }
        
        for (int j = 0; j < nums.size(); ++j) {
            if (vis[j]) continue;

            vis[j] = true;
            cur.emplace_back(nums[j]);
            dfs(nums, 0, vis, cur);
            cur.pop_back();
            vis[j] = false;
        }
    }

    std::vector<std::vector<int>> res;
};
