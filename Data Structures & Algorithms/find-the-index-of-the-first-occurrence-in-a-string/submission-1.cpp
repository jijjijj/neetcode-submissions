class Solution {
public:
    int strStr(string haystack, string needle) {
        haystack = needle + "#" + haystack;

        std::vector<int> z(haystack.size());

        int l = 0;
        int r = -1;
        int ans = -1;
        for (int i = 1; i < haystack.size(); ++i) {
            if (i <= r) {
                z[i] = std::min(z[i - l], r - i + 1);
            }

            while (i + z[i] < haystack.size() &&
                haystack[i + z[i]] == haystack[z[i]]) {
                ++z[i];
            }

            if (i + z[i] - 1 > r) {
                r = i + z[i] - 1;
                l = i;
            }

            if (z[i] == needle.size()) {
                ans = i - needle.size() - 1;
                break;
            }
        }

        return ans;
    }
};