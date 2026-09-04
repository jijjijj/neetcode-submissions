class Solution {
public:
    // +recursive
    // +one stack
    // two stacks
    string decodeString(string str) {
        std::vector<std::string> s;
        
        for (const char c : str) {
            if (c != ']') {
                s.push_back(std::string(1, c));
            } else {
                std::string sss;
                while (!s.empty() && s.back()[0] != '[') {
                    sss = s.back() + sss;
                    s.pop_back();
                }
                s.pop_back();
                int k = 0;
                int pw = 1;
                while (!s.empty() && std::isdigit(s.back()[0])) {
                    k += pw * (s.back()[0] - '0');
                    pw *= 10;
                    s.pop_back();
                }
                std::string cur;
                while (k-- > 0) cur += sss;
                s.push_back(cur);
            }
        }

        std::string res;
        for (int i = 0; i < s.size(); ++i) res += s[i];
        return res;
    }
};