class Solution {
public:
    string reorganizeString(string s) {
        // count, char
        using val_t = std::tuple<int, char>;
        std::priority_queue<val_t> pq;

        std::unordered_map<char, int> freq;
        for (const char c : s) ++freq[c];

        for (const auto [c, f] : freq) {
            pq.push({ f, c });
        }

        // pos, cnt, ch
        std::queue<std::tuple<int, int, char>> q;

        std::string res;
        res.reserve(s.size());

        while (!pq.empty() || !q.empty()) {
            const int pos = res.size();

            if (!q.empty()) {
                const auto [i, cnt, c] = q.front();
                if (i <= pos) {
                    pq.push({ cnt, c });
                    q.pop();
                } else if (pq.empty()) {
                    return "";
                }
            }

            const auto [cnt, ch] = pq.top();
            // std::cout << cnt << " " << ch << std::endl;
            pq.pop();

            res += ch;

            if (cnt > 1) {
                q.push({ pos + 2, cnt - 1, ch });
            }
        }

        return res;
    }
};