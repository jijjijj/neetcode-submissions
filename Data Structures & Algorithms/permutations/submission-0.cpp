class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> res;

        std::vector<int> perm;
        std::unordered_set<int> visited;
        dfs(nums, perm, visited, res);

        return res;
    }

private:
    void dfs(const std::vector<int>& nums,
        std::vector<int>& perm, std::unordered_set<int>& visited,
        std::vector<std::vector<int>>& res) {
        if (perm.size() == nums.size()) {
            res.emplace_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!visited.contains(i)) {
                visited.emplace(i);
                perm.emplace_back(nums[i]);

                dfs(nums, perm, visited, res);

                perm.pop_back();
                visited.erase(i);
            }
        }
    }
};
