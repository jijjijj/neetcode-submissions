class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_map<int, std::string> mp;
        std::unordered_map<std::string, int> words;

        mp[0] = beginWord;
        words[beginWord] = 0;

        int i = 1;
        for (const auto& word : wordList) {
            mp[i] = word;
            words[word] = i++;
        }

        int dist = 0;
        std::unordered_set<int> vis;
        std::queue<int> q;
        q.push(0);

        while (!q.empty()) {
            ++dist;
            
            for (int i = q.size(); i > 0; --i) {
                const auto s = q.front();
                q.pop();

                vis.emplace(s);
                if (mp[s] == endWord) return dist;

                std::string str = mp[s];

                for (int j = 0; j < str.size(); ++j) {
                    const char tmp = str[j];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        str[j] = c;
                        if (c == tmp) continue;
                        if (!words.contains(str)) continue;
                        if (vis.contains(words[str])) continue;

                        q.push(words[str]);
                    }

                    str[j] = tmp;
                }
            }
        }

        return 0;
    }
};
