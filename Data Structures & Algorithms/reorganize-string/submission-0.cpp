class Solution {
public:
    string reorganizeString(string s) {
        // closest position, count, char
        using val_t = std::tuple<int, int, char>;
        std::priority_queue<val_t,
            std::vector<val_t>, std::greater<>> q;

        std::unordered_map<char, int> freq;
        for (const char c : s) ++freq[c];

        for (const auto [c, f] : freq) {
            q.push({ 0, -f, c });
        }

        std::string res;
        res.reserve(s.size());

        while (!q.empty()) {
            const int pos = res.size();
            const auto [i, cnt, ch] = q.top();
            
            if (i <= pos) {
                q.pop();
            } else {
                return "";
            }

            res += ch;

            if (std::abs(cnt) > 1) {
                q.push({ pos + 2, -(std::abs(cnt) - 1), ch });
            }
        }

        return res;
    }
};