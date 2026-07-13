class Solution {
public:
    int numDecodings(string s) {
        // std::vector<int> dp(s.size() + 1);

        int dp_1 = 1;
        int dp_2 = 0;

        for (int i = 1; i <= s.size(); ++i) {
            int tmp = 0;
            if (s[i - 1] != '0') tmp += dp_1;
            if (i > 1 && (s[i - 2] == '1' ||
                (s[i - 2] == '2' && s[i - 1] < '7'))) tmp += dp_2;
            dp_2 = dp_1;
            dp_1 = tmp;
        }

        return dp_1;
    }
};
