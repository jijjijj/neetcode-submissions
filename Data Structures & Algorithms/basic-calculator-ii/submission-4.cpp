class Solution {
public:
    int calculate(string s) {
        std::stack<int> data;
        char op = '+';
        int num = 0;

        for (int i = 0; i < s.size(); ++i) {
            const char c = s[i];

            if (std::isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            if ((!std::isdigit(c) && c != ' ') ||
                i == s.size() - 1) {
                switch (op) {
                    case '+':
                        data.push(num);
                        break;
                    case '-':
                        data.push(-num);
                        break;
                    case '*': {
                        data.top() *= num;
                        break;
                    }
                    case '/': {
                        data.top() /= num;
                        break;
                    }
                }

                op = c;
                num = 0;
            }
        }

        int res = 0;
        while (!data.empty()) {
            res += data.top();
            data.pop();
        }
        return res;
    }
};