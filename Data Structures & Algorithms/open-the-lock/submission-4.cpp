class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        std::queue<std::string> q;
        q.push("0000");

        std::unordered_set<std::string> dead(deadends.begin(),
            deadends.end());
        std::unordered_set<std::string> vis =
            { "0000" };

        int dist = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                auto c = q.front();
                q.pop();

                if (dead.contains(c)) continue;
                if (c == target) return dist;
                
                for (int j = 0; j < 4; ++j) {
                    const char tmp = c[j];
                    for (const int d : { 1, -1 }) {
                        const int idx = tmp - '0';

                        c[j] = '0' + ((10 + idx + d) % 10);

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