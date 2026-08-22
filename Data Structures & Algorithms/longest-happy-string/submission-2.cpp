class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        std::priority_queue<
            std::pair<int, char>> q;
        if (a) q.push({ a, 'a' });
        if (b) q.push({ b, 'b' });
        if (c) q.push({ c, 'c' });

        std::string res;
        char last = 0;
        char last2 = 0;

        while (!q.empty()) {
            auto [f, c] = q.top();
            q.pop();

            if (c != last || c != last2) {
                res += c;
                last2 = last;
                last = c;
                if (f > 1) q.push({ f - 1, c });
            } else if (!q.empty()) {
                auto [f1, c1] = q.top();
                q.pop();
                res += c1;
                last2 = last;
                last = c1;
                if (f1 > 1) q.push({ f1 - 1, c1 });
                q.push({ f, c });
            } else {
                break;
            }
        }

        return res;
    }
};