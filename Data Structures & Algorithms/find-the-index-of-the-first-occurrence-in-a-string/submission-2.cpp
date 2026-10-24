class Solution {
public:
    int strStr(string haystack, string needle) {
        haystack = needle + "#" + haystack;

        std::vector<int> p(haystack.size());

        for (int i = 1; i < haystack.size(); ++i) {
            int j = p[i - 1];

            while (j && haystack[j] != haystack[i]) {
                j = p[j - 1];
            }

            p[i] = j + (haystack[i] == haystack[j]);

            if (p[i] == needle.size()) {
                return i - 2 * needle.size();
            }
        }

        return -1;
    }
};