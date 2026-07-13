class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<std::string> words(
            wordList.begin(), wordList.end());

        if (!words.contains(endWord)) return 0;

        std::unordered_map<std::string, int> bv;
        std::unordered_map<std::string, int> ev;
        bv[beginWord] = 1;
        ev[endWord] = 1;

        std::queue<std::string> bq;
        std::queue<std::string> eq;
        bq.push(beginWord);
        eq.push(endWord);

        while (!bq.empty() && !eq.empty()) {
            if (bq.size() > eq.size()) {
                std::swap(bq, eq);
                std::swap(bv, ev);
            }

            for (int j = bq.size(); j > 0; --j) {
                std::string word = bq.front();

                for (int i = 0; i < word.size(); ++i) {
                    const char tmp = word[i];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (!words.contains(word) || tmp == c) continue;

                        if (ev.contains(word)) {
                            return bv[bq.front()] + ev[word];
                        }
                        if (bv.contains(word)) continue;
                        bv[word] = bv[bq.front()] + 1;
                        // words.erase(word);
                        bq.push(word);
                    }

                    word[i] = tmp;
                }

                bq.pop();
            }
        }

        return 0;
    }
};
