class Solution {
public:
    int calculate(string s) {
        char op = '+';
        int res = 0;
        int num = 0;
        int prev = 0;

        for (int i = 0; i < s.size(); ++i) {
            const char c = s[i];

            if (std::isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            if ((!std::isdigit(c) && c != ' ') ||
                i == s.size() - 1) {
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
        }

        return res + prev;
    }
};