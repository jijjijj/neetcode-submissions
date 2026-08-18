class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        std::unordered_set<std::string> dead(
            deadends.begin(), deadends.end());

        std::queue<std::string> q;
        q.push("0000");

        std::unordered_set<std::string> vis;
        vis.emplace("0000");

        int dist = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                auto c = q.front();
                q.pop();

                if (c == target) return dist;
                if (dead.contains(c)) continue;

                for (int j = 0; j < 4; ++j) {
                    const int idx = c[j] - '0';

                    std::string up = c;
                    up[j] = '0' + ((idx + 1) % 10);
                    std::string down = c;
                    down[j] = '0' + (idx > 0 ? idx - 1 : 9);

                    if (!vis.contains(up)) {
                        vis.emplace(up);
                        q.push(up);
                    }
                    if (!vis.contains(down)) {
                        vis.emplace(down);
                        q.push(down);
                    }
                }
            }

            ++dist;
        }

        return -1;
    }
};