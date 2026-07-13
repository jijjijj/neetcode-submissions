class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_map<std::string,
            std::vector<std::string>> words;

        wordList.emplace_back(beginWord);
        for (auto& word : wordList) {
            for (int i = 0; i < word.size(); ++i) {
                std::string w = word;
                w[i] = '*';

                words[w].emplace_back(word);
            }
        }

        int dist = 0;
        std::unordered_set<std::string> vis;
        std::queue<std::string> q;
        q.push(beginWord);

        while (!q.empty()) {
            ++dist;
            
            for (int i = q.size(); i > 0; --i) {
                auto& s = q.front();

                vis.emplace(s);
                if (s == endWord) return dist;

                for (int j = 0; j < s.size(); ++j) {
                    const char tmp = s[j];
                    s[j] = '*';

                    for (const auto& word : words[s]) {
                        if (vis.contains(word)) continue;
                        q.push(word);
                    }

                    s[j] = tmp;
                }

                q.pop();
            }
        }

        return 0;
    }
};
