class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::vector<int> indeg(n + 1);
        std::vector<int> outdeg(n + 1);

        for (const auto& edge : trust) {
            const int a = edge[0];
            const int b = edge[1];

            ++indeg[b];
            ++outdeg[a];
        }

        for (int i = 1; i <= n; ++i) {
            if (!outdeg[i] && indeg[i] == (n - 1)) return i;
        }

        return -1;
    }
};