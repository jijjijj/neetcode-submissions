class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::unordered_set<int> vis;
        std::queue<int> q;
        q.push(0);

        int dist = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                const int v = q.front();
                q.pop();

                if (v == amount) return dist;
                if (v > amount) continue;

                for (const int c : coins) {
                    if (vis.contains(c + v) || c > amount) continue;
                    vis.emplace(c + v);
                    q.push(c + v);
                }
            }
            ++dist;
        }

        return -1;
    }
};
