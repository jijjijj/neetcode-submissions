class Solution {
public:
    // +recursive
    // one stack
    // two stacks
    string decodeString(string str) {
        std::stack<std::string> s;
        
        for (const char c : str) {
            if (c != ']') {
                s.push(std::string(1, c));
            } else {
                std::string sss;
                while (!s.empty() && s.top()[0] != '[') {
                    sss = s.top() + sss;
                    s.pop();
                }
                s.pop();
                int k = 0;
                int pw = 1;
                while (!s.empty() && std::isdigit(s.top()[0])) {
                    k += pw * (s.top()[0] - '0');
                    pw *= 10;
                    s.pop();
                }
                std::string cur;
                while (k-- > 0) cur += sss;
                s.push(cur);
            }
        }

        std::string res;
        while (!s.empty()) {
            res = s.top() + res;
            s.pop();
        }
        return res;
    }
};