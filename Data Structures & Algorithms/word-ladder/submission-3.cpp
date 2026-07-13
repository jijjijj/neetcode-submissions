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

                words[word].emplace_back(std::move(w));
            }
        }

        int dist = 0;
        std::unordered_set<std::string> vis;
        std::queue<std::string> q;
        q.push(beginWord);

        while (!q.empty()) {
            ++dist;
            
            for (int i = q.size(); i > 0; --i) {
                const auto s = q.front();
                q.pop();

                vis.emplace(s);
                if (s == endWord) return dist;

                for (const auto& word : words[s]) {
                    if (vis.contains(word)) continue;
                    q.push(word);
                }
            }
        }

        return 0;
    }
};
