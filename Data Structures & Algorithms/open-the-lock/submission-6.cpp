class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        std::queue<std::string> q;
        q.push("0000");

        std::queue<std::string> q2;
        q2.push(target);

        std::unordered_set<std::string> dead(deadends.begin(),
            deadends.end());
        std::unordered_set<std::string> vis =
            { "0000" };
        std::unordered_set<std::string> vis2 =
            { target };

        int dist = 0;
        while (!q.empty() && !q2.empty()) {
            if (q2.size() < q.size()) {
                std::swap(q, q2);
                std::swap(vis, vis2);
            }

            for (int i = q.size(); i > 0; --i) {
                auto c = q.front();
                q.pop();

                if (dead.contains(c)) continue;
                if (vis2.contains(c)) return dist;
                // if (c == target) return dist;
                
                for (int j = 0; j < 4; ++j) {
                    const char tmp = c[j];
                    for (const int d : { 1, -1 }) {
                        const int idx = tmp - '0';

                        c[j] = '0' + ((10 + idx + d) % 10);

                        // if (vis2.contains(c)) return dist + 1;
                        if (!vis.contains(c)) {
                            vis.emplace(c);
                            q.push(c);
                        }
                    }
                    c[j] = tmp;
                }
            }

            ++dist;
        }

        return -1;
    }
};