class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        std::unordered_map<char, std::unordered_set<char>> e(27);

        const auto ch = [](const std::string& s, int i) {
            return i < s.size() ? s[i] : static_cast<char>('a' - 1);
        };

        std::unordered_map<char, int> indeg;
        for (const auto& w : words) for (const char c : w) indeg[c];

        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                for (int k = 0; k < std::max(
                    words[i].size(), words[j].size()); ++k) {
                    const char a = ch(words[i], k);
                    const char b = ch(words[j], k);
                    if (a != b) {
                        if (e[a].contains(b)) break;
                        // std::cout << words[i] << " " << words[j] << ": ";
                        // std::cout << a << "->" << b << std::endl;
                        e[a].emplace(b);
                        ++indeg[b];
                        break;
                    }
                }
            }
        }

        if (indeg.contains('a' - 1)) return "";

        int to_clear = indeg.size();
        int total = 0;

        // kahn's
        std::queue<char> q;

        for (const auto [ch, in] : indeg) {
            if (!in) q.push(ch);
        }

        std::string res;

        while (!q.empty()) {
            auto v = q.front();
            q.pop();


            // std::cout << v << " ";
            res += v;

            ++total;

            for (const auto to : e[v]) {
                if (!--indeg[to]) q.push(to);
            }
        }

        if (total != to_clear) return "";

        return res;
    }
};
