class Solution {
public:
    // +max freq hashmap
    // prior queue
    // set characters
    std::string reorganizeString(string s) {
        std::unordered_map<char, int> freq;
        for (const char c : s) ++freq[c];

        std::priority_queue<std::pair<int, char>> q;
        for (const auto [c, f] : freq) q.push({ f, c });

        std::string res;

        std::pair<int, char> prev{};

        while (!q.empty() || prev.first) {
            if (q.empty() && prev.first) return "";

            const auto [f, c] = q.top();
            q.pop();

            res += c;

            if (prev.first) {
                q.push(prev);
            }

            prev = { f - 1, c };
        }

        return res;
    }
};