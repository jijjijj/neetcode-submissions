class Solution {
public:
    // find_max
    // heap
    // rec
    string longestDiverseString(int a, int b, int c) {
        std::priority_queue<
            std::pair<int, char>> q;
        q.push({ a, 'a' });
        q.push({ b, 'b' });
        q.push({ c, 'c' });

        std::string res;

        while (!q.empty()) {
            const auto [f, c] = q.top();
            q.pop();

            if (!f) break;

            if (res.size() > 1 &&
                res.back() == c && res[res.size() - 2] == c) {
                auto [f1, c1] = q.top();
                q.pop();

                if (!f1) break;

                res += c1;
                q.push({ f1 - 1, c1 });
                q.push({ f, c });
            } else if (!q.empty()) {
                res += c;
                q.push({ f - 1, c });
            }
        }

        return res;
    }
};