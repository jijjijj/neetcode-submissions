class Solution {
public:
    int calculate(string s) {
        char op = '+';
        int res = 0;
        int num = 0;
        int prev = 0;
        int i = 0;
        while (i <= s.size()) {
            const char c = i < s.size() ? s[i] : '_';
            if (c == ' ') {
                ++i;
                continue;
            }
            if (std::isdigit(c)) {
                num = num * 10 + (c - '0');
            } else {
                switch (op) {
                    case '+':
                        res += prev;
                        prev = num;
                        break;
                    case '-':
                        res += prev;
                        prev = -num;
                        break;
                    case '*': {
                        prev *= num;
                        break;
                    }
                    case '/': {
                        prev /= num;
                        break;
                    }
                }

                op = c;
                num = 0;
            }
            ++i;
        }

        return res + prev;
    }
};