class Solution {
public:
    int numSquares(int n) {
        std::queue<int> q;

        q.push(0);
        int dist = 0;

        std::unordered_set<int> vis;
        vis.emplace(0);

        while (!q.empty()) {
            ++dist;

            for (int i = q.size(); i > 0; --i) {
                const int v = q.front();
                q.pop();

                for (int j = 0; v + j * j <= n; ++j) {
                    if (vis.contains(v + j * j)) continue;
                    if ((v + j * j) == n) return dist;
                    
                    q.push(v + j * j);
                }
            }
        }

        return 0;
    }
};