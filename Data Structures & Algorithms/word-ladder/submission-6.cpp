class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end() ||
            beginWord == endWord)
            return 0;
        std::unordered_set<std::string> words(wordList.begin(), wordList.end());

        std::queue<std::string> bq;
        std::queue<std::string> eq;

        bq.push(beginWord);
        eq.push(endWord);

        std::unordered_map<std::string, int> fb, fe;

        fb[beginWord] = 1;
        fe[endWord] = 1;

        while (!bq.empty() && !eq.empty()) { // why?
            if (bq.size() > eq.size()) {
                std::swap(bq, eq);
                std::swap(fb, fe);
            }

            for (int i = bq.size(); i > 0; --i) {
                auto& s = bq.front();

                const int steps = fb[s];
                for (int j = 0; j < s.size(); ++j) {
                    const char tmp = s[j];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        s[j] = c;

                        if (tmp == c) continue;
                        if (!words.contains(s)) continue;
                        if (fe.contains(s)) {
                            return fe[s] + steps;
                        }
                        if (!fb.contains(s)) {
                            fb[s] = steps + 1;
                            bq.push(s);
                        }
                    }

                    s[j] = tmp;
                }

                bq.pop();
            }
        }

        return 0;
    }
};
