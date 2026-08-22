class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        std::priority_queue<
            std::pair<int, char>> q;
        if (a) q.push({ a, 'a' });
        if (b) q.push({ b, 'b' });
        if (c) q.push({ c, 'c' });

        std::string res;

        std::pair<int, char> prev{};
        while (!q.empty() || prev.first) {
            if (q.empty() && prev.first) break;
            auto [f, c] = q.top();
            q.pop();

            res += c;
            --f;
            if (f) {
                res += c;
                --f;
            }

            if (prev.first) {
                q.push(prev);
            }

            prev = { f, c };
        }

        return res;
    }
};