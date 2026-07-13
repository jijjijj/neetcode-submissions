class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int maxi = 0;
        int maxr = 0;

        const std::vector<int> man = manachers(s);

        for (int i = 0; i < man.size(); ++i) {
            if (man[i] > maxr) {
                maxi = i;
                maxr = man[i];
            }
        }

        // std::cout << maxi << " " << maxr << std::endl;
        // return {};
        
        int start = (maxi - maxr + 1) / 2;
        return s.substr(start, maxr - 1);
    }

private:
    std::vector<int> manachers(const std::string& s) const {
        std::string str(s.size() * 2 + 1, '#');

        for (int i = 0; i < s.size(); ++i)
            str[i * 2 + 1] = s[i];

        std::vector<int> p(str.size());

        int l = 0;
        int r = 0;

        for (int i = 0; i < str.size(); ++i) {
            p[i] = i <= r ? std::min(r - i, p[l + r - i]) : 0;
            // std::cout << i << ": " << p[i] << std::endl;
            while (i + p[i] < str.size() &&
                i - p[i] >= 0 &&
                str[i - p[i]] == str[i + p[i]]) ++p[i];
            // std::cout << i << ": " << p[i] << std::endl;

            if (i + p[i] - 1 > r) {
                r = i + p[i] - 1;
                l = i - p[i] + 1;
                // std::cout << l << " " << r << std::endl;
            }
        }

        return p;
    }
};
