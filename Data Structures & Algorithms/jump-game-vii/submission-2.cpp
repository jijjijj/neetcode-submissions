class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int n = s.size();
        std::queue<int> q;
        q.push(0);

        std::vector<bool> vis(n);
        int max = 0;
        while (!q.empty()) {
            const int v = q.front();
            q.pop();

            if (v == n - 1) return true;

            int i = std::max(max + 1, v + minJump);
            max = std::min(n - 1, v + maxJump);
            for (; i <= max; ++i) {
                if (s[i] != '1' && !vis[i]) {
                    vis[i] = true;
                    q.push(i);
                }
            }
        }

        return false;
    }
};