class Solution {
public:
    bool checkValidString(string s) {
        const int n = s.size();

        int openMin = 0;
        int openMax = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                --openMin;
                ++openMax;
            } else if (s[i] == '(') {
                ++openMin;
                ++openMax;
            } else {
                --openMin;
                --openMax;
            }

            if (openMax < 0) return false;
            if (openMin < 0) openMin = 0;
        }

        return !openMin;
    }
};
