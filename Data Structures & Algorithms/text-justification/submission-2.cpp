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

            std::string curr;
            int pos = 0;
            for (; j + 1 < i; ++j) {
                curr += words[j];
                if (last) {
                    curr += ' ';
                } else {
                    curr += std::string(spaces, ' ');
                    if (extra) {
                        curr += ' ';
                        --extra;
                    }
                }
            }
            curr += words[j];
            curr += std::string(maxWidth - curr.size(), ' ');
            res.emplace_back(curr);
        }

        return res;
    }
};