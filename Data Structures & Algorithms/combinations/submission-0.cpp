class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<int> cur;
        dfs(0, k, n, cur);

        return res;
    }

private:
    void dfs(int i, int k, int n, std::vector<int>& cur) {
        if (cur.size() == k) {
            res.emplace_back(cur);
            return;
        }

        for (int j = i + 1; j <= n; ++j) {
            cur.emplace_back(j);
            dfs(j, k, n, cur);
            cur.pop_back();
        }
    }

    std::vector<std::vector<int>> res;
};