class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int n = s.size();
        std::queue<int> q;
        q.push(0);

        std::vector<bool> vis(n);

        while (!q.empty()) {
            const int v = q.front();
            q.pop();

            if (v == n - 1) return true;

            for (int i = v + minJump; i <=
                std::min(n - 1, v + maxJump); ++i) {
                if (s[i] != '1' && !vis[i]) {
                    vis[i] = true;
                    q.push(i);
                }
            }
        }

        return false;
    }
};