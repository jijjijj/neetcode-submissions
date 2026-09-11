class Solution {
public:
    string longestPalindrome(string s) {
        std::string s2(s.size() * 2 + 1, '#');
        for (int i = 0; i < s.size(); ++i) s2[i * 2 + 1] = s[i];

        const auto ans = man(s2);
        std::string res;
        for (int i = ans.first - ans.second + 1;
            i < ans.first + ans.second; ++i) {
            if (s2[i] != '#') res += s2[i];
        }
        return res;
    }

private:
    std::pair<int, int> man(const std::string& s) {
        std::vector<int> m(s.size(), 1);

        // #a#v#a#b#
        int l = 0;
        int r = -1;
        int max = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i <= r) {
                m[i] = std::max(m[l + r - i], r - i + 1);
            }

            while (i + m[i] < s.size() &&
                i - m[i] >= 0 &&
                s[i - m[i]] == s[i + m[i]]) ++m[i];
            
            if (i + m[i] - 1 > r) {
                l = i - m[i] + 1;
                r = i + m[i] - 1;
            }

            if (m[i] > m[max]) max = i;
        }

        return { max, m[max] };
    }
};
