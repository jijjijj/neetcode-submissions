class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_map<int,
            std::vector<int>> words;
        std::unordered_map<int, std::string> mp;

        for (const auto& word : wordList) mp[mp.size()] = word;
        mp[mp.size()] = beginWord;

        wordList.emplace_back(beginWord);

        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                int diff = 0;
                for (int t = 0; t < wordList[i].size(); ++t) {
                    if (wordList[i][t] != wordList[j][t]) ++diff;
                }

                if (diff == 1) {
                    words[i].emplace_back(j);
                    words[j].emplace_back(i);
                }
            }
        }

        int dist = 1;

        std::unordered_set<int> vis;
        
        std::queue<int> q;
        q.push(mp.size() - 1);

        while (!q.empty()) {
            for (int j = q.size(); j > 0; --j) {
                const auto s = q.front();
                q.pop();

                if (mp[s] == endWord) return dist;
                vis.emplace(s);

                for (const auto& to : words[s]) {
                    if (vis.contains(to)) continue;
                    
                    q.push(to);
                }
            }

            ++dist;
        }

        return 0;
    }
};
