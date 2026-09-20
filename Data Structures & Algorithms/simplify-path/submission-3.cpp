class Solution {
public:
    string simplifyPath(string path) {
        std::string token;
        std::vector<std::string> s;

        for (const char c : path + "/") {
            if (c == '/') {
                if (token == "..") {
                    if (!s.empty()) s.pop_back();
                } else if (!token.empty() && token != ".") {
                    s.push_back(std::move(token));
                }
                token.clear();
            } else {
                token += c;
            }
        }

        std::string res = "/";

        for (int i = 0; i < s.size(); ++i) {
            if (i > 0) res += "/";
            res += s[i];
        }

        return res;
    }
};