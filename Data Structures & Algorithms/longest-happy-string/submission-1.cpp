class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        std::priority_queue<
            std::pair<int, char>> q;
        if (a) q.push({ a, 'a' });
        if (b) q.push({ b, 'b' });
        if (c) q.push({ c, 'c' });

        std::string res;

        while (!q.empty()) {
            auto [f, c] = q.top();
            q.pop();

            res += c;
            --f;
            if (f) {
                res += c;
                --f;
            }

            if (q.empty()) break;

            auto [f1, c1] = q.top();
            q.pop();

            res += c1;
            --f1;

            if (f) q.push({ f, c });
            if (f1) q.push({ f1, c1 });
        }

        return res;
    }
};