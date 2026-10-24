class Solution {
public:
    int strStr(string haystack, string needle) {
        std::vector<int> p(needle.size() + 1);

        for (int i = 1; i < needle.size(); ++i) {
            int j = p[i - 1];

            while (j && needle[j] != needle[i]) {
                j = p[j - 1];
            }

            p[i] = j + (needle[i] == needle[j]);
        }

        int last = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            int j = last;

            while (j && needle[j] != haystack[i]) {
                j = p[j - 1];
            }

            last = j + (haystack[i] == needle[j]);

            if (last == needle.size()) return i - needle.size() + 1;
        }

        return -1;
    }
};