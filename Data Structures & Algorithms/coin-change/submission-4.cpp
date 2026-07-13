class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::queue<int> q;
        q.push(0);

        std::vector<bool> vis(amount + 1);
        vis[0] = true;

        int dist = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                const int v = q.front();
                q.pop();

                if (v == amount) return dist;

                for (int c : coins) {
                    if (c > amount - v || vis[c + v]) continue;
                    vis[c + v] = true;
                    q.push(c + v);
                }
            }
            ++dist;
        }

        return -1;
    }
};
