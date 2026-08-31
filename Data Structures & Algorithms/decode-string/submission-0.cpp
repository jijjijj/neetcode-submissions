class Solution {
public:
    string decodeString(string str) {
        std::stack<std::string> s;

        int cur = 0;
        for (int i = 0; i < str.size(); ++i) {
            const char c = str[i];
            std::string add;
            if (std::isdigit(c)) {
                cur *= 10;
                cur += (c - '0');
                continue;
            } else if (c == '[') {
                s.push(std::to_string(cur));
                s.push("");
                cur = 0;
                continue;
            } else if (c == ']') {
                const std::string part = s.top();
                s.pop();
                const int times = std::stoi(s.top());
                s.pop();
                std::stringstream ss;
                for (int i = 0; i < times; ++i) {
                    ss << part;
                }
                add = ss.str();
            } else {
                add = c;
            }

            std::string prev;
            if (!s.empty()) {
                prev = s.top();
                s.pop();
            }
            s.push(prev + add);
        }

        return s.top();
    }
};