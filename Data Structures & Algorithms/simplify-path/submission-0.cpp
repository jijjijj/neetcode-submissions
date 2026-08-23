class Solution {
public:
    string simplifyPath(string path) {
        std::vector<std::string> tokens;

        for (const char c : path) {
            if (c == '/') {
                tokens.emplace_back(std::string{c});
            } else {
                if (tokens.empty() || tokens.back() == "/") {
                    tokens.emplace_back(std::string{c});
                } else {
                    tokens.back() += c;
                }
            }
        }

        std::stack<std::string> s;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "/") {
                if (s.empty() || s.top() != "/") {
                    s.push(tokens[i]);
                }
            } else if (tokens[i] == ".") {
                // ignore
            } else if (tokens[i] == "..") {
                if (!s.empty()) s.pop();
                if (!s.empty()) s.pop();
            } else {
                s.push(tokens[i]);
            }
        }

        if (s.size() > 1 && s.top() == "/") s.pop();

        std::string res;

        while (!s.empty()) {
            res = s.top() + res;
            s.pop();
        }

        return res;
    }
};