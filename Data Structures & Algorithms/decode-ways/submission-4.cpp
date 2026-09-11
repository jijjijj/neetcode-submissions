class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();
        int dp1 = 1;
        int dp2 = 0;

        for (int i = n - 1; i >= 0; --i) {
            int tmp = 0;
            if (s[i] != '0') {
                tmp = dp1;
                if (i < n - 1 &&
                    (s[i] == '1' ||
                        (s[i] == '2' && s[i + 1] <= '6'))) {
                    tmp += dp2;
                }
            }
            dp2 = dp1;
            dp1 = tmp;
        }

        return dp1;
    }
};
