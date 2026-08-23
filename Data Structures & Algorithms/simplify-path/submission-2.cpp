class Solution {
public:
    string simplifyPath(string path) {
        std::string token;
        std::stringstream ss;
        ss << path;
        std::vector<std::string> s;

        while (std::getline(ss, token, '/')) {
            if (token == "..") {
                if (!s.empty()) s.pop_back();
            } else if (!token.empty() && token != ".") {
                s.emplace_back(std::move(token));
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