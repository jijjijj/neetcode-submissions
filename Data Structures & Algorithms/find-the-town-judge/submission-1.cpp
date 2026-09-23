class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::vector<int> delta(n + 1);

        for (const auto& edge : trust) {
            const int a = edge[0];
            const int b = edge[1];

            ++delta[b];
            --delta[a];
        }

        for (int i = 1; i <= n; ++i) {
            if (delta[i] == (n - 1)) return i;
        }

        return -1;
    }
};