class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<std::string> words(
            wordList.begin(), wordList.end());

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

                    for (char c = 'a'; c <= 'z'; ++c) {
                        s[i] = c;

                        if (tmp == c) continue;
                        if (!words.contains(s) || vis.contains(s)) continue;

                        q.push(s);
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
