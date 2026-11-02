class Solution {
public:
    vector<string> fullJustify(
        vector<string>& words, int maxWidth) {
        std::vector<std::string> res;

        int i = 0;

        while (i < words.size()) {
            int space = 0;
            int j = i;
            while (i < words.size() &&
                space + words[i].size() + (i - j) <= maxWidth) {
                space += words[i].size();
                ++i;
            }

            int spaces = maxWidth - space;
            int gaps = std::max(i - j - 1, 1);
            int extra = spaces % gaps;
            spaces /= gaps;
            const bool last = (i == words.size());

            std::string curr(maxWidth, ' ');
            int pos = 0;
            for (; j < i; ++j) {
                std::copy(words[j].begin(), words[j].end(),
                    curr.begin() + pos);
                pos += words[j].size();
                if (last) {
                    ++pos;
                } else {
                    pos += spaces;
                    if (extra) {
                        ++pos;
                        --extra;
                    }
                }
            }
            res.emplace_back(curr);
        }

        return res;
    }
};