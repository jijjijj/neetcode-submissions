class Solution {
public:
    int countSubstrings(string s) {
        int total = 0;

        const std::vector<int> man = manacher(s);

        for (int i : man) {
            total += (i + 1) / 2;
        }

        return total;
    }

private:
    std::vector<int> manacher(const std::string& s) const {
        std::string t(s.size() * 2 + 1, '#');

        for (int i = 0; i < s.size(); ++i) t[i * 2 + 1] = s[i];

        std::vector<int> p(t.size());

        int l = 0;
        int r = 0;
        for (int i = 0; i < t.size(); ++i) {
            p[i] = i <= r ? std::min(r - i, p[l + (r - i)]) : 0;

            while (i - p[i] - 1 >= 0 &&
                i + p[i] + 1 < t.size() &&
                t[i - p[i] - 1] == t[i + p[i] + 1]) ++p[i];

            if (i + p[i] > r) {
                r = i + p[i];
                l = i - p[i];
            }
        }

        return p;
    }
};
