class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return calc(s, i, false);
    }

private:
    int calc(const std::string& s, int& i, bool die) {
        int res = 0;

        for (; i < s.size(); ) {
            const char c = s[i];

            if (c == ' ') {
                ++i;
                continue;
            }
            if ((c == '+' || c == '-') && die) break;

            if (std::isdigit(c)) {
                res += num(s, i);
                continue;
            }
            
            ++i;
            if (c == '+') {
                res += calc(s, i, true);
            } else if (c == '-') {
                res -= calc(s, i, true);
            } else if (c == '*') {
                res *= num(s, i);
            } else if (c == '/') {
                res /= num(s, i);
            }
        }
        // std::cout << res << " ";
        return res;
    }

private:
    int num(const std::string& s, int& i) {
        int res = 0;
        while (s[i] == ' ') ++i;
        while (i < s.size() && std::isdigit(s[i])) {
            res *= 10;
            res += (s[i] - '0');
            ++i;
        }

        return res;
    }
};