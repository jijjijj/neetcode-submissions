class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();

        int maxi = 0;
        int maxl = 0;

        for (int i = 0; i < s.size(); ++i) {
            int l = i;
            int r = i;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxl) {
                    maxl = r - l + 1;
                    maxi = l;
                }
                --l;
                ++r;
            }

            l = i;
            r = i + 1;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxl) {
                    maxl = r - l + 1;
                    maxi = l;
                }
                --l;
                ++r;
            }
        }

        return s.substr(maxi, maxl);
    }
};
