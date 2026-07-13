class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_map<
            std::string,
            std::vector<std::string>> edges;

        wordList.emplace_back(beginWord);

        for (const auto& word : wordList) {
            for (const auto& word_to : wordList) {
                if (word == word_to ||
                    word.size() != word_to.size()) continue;

                int skip = 0;
                for (int i = 0; i < word.size(); ++i) {
                    if (word[i] != word_to[i]) {
                        ++skip;

                        if (skip > 1) break;
                    }
                } 

                if (skip > 1) continue;
                
                edges[word].emplace_back(word_to);
            }
        }

        int dist = 0;
        std::unordered_set<std::string> vis;
        std::queue<std::string> q;
        q.push(beginWord);

        while (!q.empty()) {
            ++dist;

            for (int i = q.size(); i > 0; --i) {
                auto s = q.front();
                q.pop();

                vis.emplace(s);
                if (s == endWord) return dist;

                for (const auto& to : edges[s]) {
                    if (vis.contains(to)) continue;
                    q.push(to);
                }
            }
        }

        return 0;
    }
};
