class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        std::vector<int> o(26);

        for (int i = 0; i < order.size(); ++i) o[order[i] - 'a'] = i;

        for (int i = 1; i < words.size(); ++i) {
            const auto& w1 = words[i - 1];
            const auto& w2 = words[i];

            for (int j = 0; j < w1.size(); ++j) {
                if (j == w2.size()) return false;
                const int o1 = o[w1[j] - 'a'];
                const int o2 = o[w2[j] - 'a'];
                if (o1 > o2) return false;
                if (o1 < o2) break;
            }
        }

        return true;
    }
};