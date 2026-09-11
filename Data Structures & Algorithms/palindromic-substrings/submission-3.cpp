class Solution {
public:
    int countSubstrings(string in) {
        std::string s(in.size() * 2 + 1, '#');
        for (int i = 0; i < in.size(); ++i) s[i * 2 + 1] = in[i];

        std::vector<int> m(s.size(), 1);

        int l = 0;
        int r = -1;
        int sum = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (i <= r) {
                m[i] = std::min(m[l + (r - i)], r - i + 1);
            }

            while (i + m[i] < s.size() &&
                i - m[i] >= 0 &&
                s[i + m[i]] == s[i - m[i]]) ++m[i];

            if (i + m[i] - 1 > r) {
                r = i + m[i] - 1;
                l = i - m[i] + 1;
            }
            // 1+2+1
            sum += m[i] / 2;
        }

        return sum;
    }
};
