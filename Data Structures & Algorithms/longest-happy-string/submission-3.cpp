class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        std::priority_queue<
            std::pair<int, char>> q;
        q.push({ a, 'a' });
        q.push({ b, 'b' });
        q.push({ c, 'c' });

        std::string res;
        char last = 0;
        char last2 = 0;

        while (!q.empty()) {
            const auto [f, c] = q.top();
            q.pop();

            if (!f) break;

            if (c != last || c != last2) {
                res += c;
                last2 = last;
                last = c;
                q.push({ f - 1, c });
            } else if (!q.empty()) {
                auto [f1, c1] = q.top();
                q.pop();

                if (!f1) break;

                res += c1;
                last2 = last;
                last = c1;
                q.push({ f1 - 1, c1 });
                q.push({ f, c });
            } else break;
        }

        return res;
    }
};