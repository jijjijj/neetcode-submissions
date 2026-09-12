class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        std::vector<int> o(26);

        for (int i = 0; i < order.size(); ++i) o[order[i] - 'a'] = i;

        for (int i = 1; i < words.size(); ++i) {
            const int len = std::min(words[i].size(),
                words[i - 1].size());
            
            for (int j = 0; j < len; ++j) {
                const int o1 = o[words[i - 1][j] - 'a'];
                const int o2 = o[words[i][j] - 'a'];
                if (o1 > o2) return false;
                if (o1 < o2) break;
            }

            if (words[i][len - 1] == words[i - 1][len - 1] &&
                words[i].size() < words[i - 1].size()) return false;
        }

        return true;
    }
};