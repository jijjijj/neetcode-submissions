class Solution {
public:
    // bruteforce
    // dp on trees
    // diameter
    // +peeling
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        e.resize(n);
        dp.resize(n, std::vector<int>(2, 0));

        for (const auto& edge : edges) {
            e[edge[0]].emplace_back(edge[1]);
            e[edge[1]].emplace_back(edge[0]);
        }

        dfs(0, -1);
        dfs1(0, -1, 0);

        std::vector<int> res;
        int min = std::numeric_limits<int>::max();

        for (int i = 0; i < dp.size(); ++i)
            min = std::min(min, dp[i][0]);

        for (int i = 0; i < dp.size(); ++i) {
            // std::cout << dp[i][0] << " ";
            if (dp[i][0] == min) res.emplace_back(i);
        }

        return res;
    }

private:
    void dfs(int v, int p) {
        for (const int to : e[v]) {
            if (to == p) continue;

            dfs(to, v);

            const int mx = 1 + dp[to][0];

            if (mx > dp[v][0]) {
                dp[v][1] = dp[v][0];
                dp[v][0] = mx;
            } else if (mx > dp[v][1]) {
                dp[v][1] = mx;
            }
        }
    }

    void dfs1(int v, int p, int max) {
        if (max > dp[v][0]) {
            dp[v][1] = dp[v][0];
            dp[v][0] = max;
        } else if (max > dp[v][1]) {
            dp[v][1] = max;
        }

        for (const int to : e[v]) {
            if (to == p) continue;

            dfs1(to, v, 1 + (dp[v][0] == dp[to][0] + 1
                ? dp[v][1] : dp[v][0]));
        }
    }

    std::vector<std::vector<int>> dp;
    std::vector<std::vector<int>> e;
};