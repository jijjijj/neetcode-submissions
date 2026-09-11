class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.size();

        int sum = 0;

        for (int i = 0; i < s.size(); ++i) {
            int l = i;
            int r = i;

            while (l >= 0 && r < s.size() &&
                s[l] == s[r]) {
                ++sum;
                --l;
                ++r;
            }

            l = i;
            r = i + 1;

            while (l >= 0 && r < s.size() &&
                s[l] == s[r]) {
                ++sum;
                --l;
                ++r;
            }
        }

        return sum;
    }
};
