class Solution {
public:
    bool isValid(string in) {
        std::stack<char> s;

        for (char c : in) {
            if (c == '(' || c == '{' || c == '[') s.push(c);
            else if (!s.empty()) {
                const char top = s.top();
                s.pop();

                if (!((top == '(' && c == ')') ||
                    (top == '[' && c == ']') ||
                    (top == '{' && c == '}'))) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return s.empty();
    }
};
