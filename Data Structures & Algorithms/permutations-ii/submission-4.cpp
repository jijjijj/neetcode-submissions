class Solution {
    vector<vector<int>> res;
    std::unordered_map<int, int> mp;
    vector<int> curr;

public:
    // hash map
    // +optimal
    // +hashset/boolarray
    // next permutation
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (const int v : nums) ++mp[v];

        dfs(nums.size());
        return res;
    }

    void dfs(int n) {
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }

        for (auto& [v, c] : mp) {
            if (!c) continue;
            curr.emplace_back(v);
            --c;
            dfs(n);
            curr.pop_back();
            ++c;
        }
    }
};