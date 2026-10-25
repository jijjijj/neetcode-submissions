class Solution {
public:
    int strStr(string haystack, string needle) {
        std::vector<int> p(needle.size());

        int i = 1;
        int last = 0;

        while (i < needle.size()) {
            if (needle[i] == needle[last]) {
                ++last;
                p[i] = last;
                ++i;
            } else if (last) {
                last = p[last - 1];
            } else {
                p[i] = 0;
                ++i;
            }
        }

        i = 0;
        int j = 0; // needle

        while (i < haystack.size()) {
            if (needle[j] == haystack[i]) {
                ++j;
                ++i;
            } else if (j) {
                j = p[j - 1];
            } else {
                ++i;
                j = 0;
            }

            if (j == needle.size())
                return i - needle.size();
        }

        return -1;
    }
};