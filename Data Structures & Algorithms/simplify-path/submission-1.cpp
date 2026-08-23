class Solution {
public:
    string simplifyPath(string path) {
        std::string token;
        std::stringstream ss;
        ss << path;
        std::stack<std::string> s;

        while (std::getline(ss, token, '/')) {
            if (token == "") {
                if (s.empty() || s.top() != "/") {
                    s.push("/");
                }
            } else if (token == ".") {
                // ignore
            } else if (token == "..") {
                if (s.size() > 1) s.pop();
                if (s.size() > 1) s.pop();
            } else {
                s.push(token);
                s.push("/");
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