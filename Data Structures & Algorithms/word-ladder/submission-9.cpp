class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_map<std::string,
            std::vector<std::string>> words;

        for (auto& word : wordList) {
            for (int i = 0; i < word.size(); ++i) {
                std::string s = word;
                s[i] = '*';
                words[s].emplace_back(word);
            }
        }

        int dist = 1;

        std::unordered_set<std::string> vis;
        
        std::queue<std::string> q;
        q.push(beginWord);

        while (!q.empty()) {
            for (int j = q.size(); j > 0; --j) {
                auto& s = q.front();

                if (s == endWord) return dist;
                vis.emplace(s);

                for (int i = 0; i < s.size(); ++i) {
                    const char tmp = s[i];

                    s[i] = '*';
                    for (const auto& to : words[s]) {
                        if (vis.contains(to)) continue;
                        
                        q.push(to);
                    }

                    s[i] = tmp;
                }

                q.pop();
            }

            ++dist;
        }

        return 0;
    }
};
