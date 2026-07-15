class Solution {
public:
    bool checkValidString(string s) {
        std::stack<int> left;
        std::stack<int> ast;

        for (int i = 0; i < s.size(); ++i) {
            const char c = s[i];

            if (c == '(') {
                left.push(i);
            } else if (c == ')') {
                if (left.empty() && ast.empty()) return false;

                if (left.empty()) {
                    ast.pop();
                } else {
                    left.pop();
                }
            } else {
                ast.push(i);
            }
        }

        while (!ast.empty() && !left.empty()) {
            if (ast.top() < left.top()) return false;

            ast.pop();
            left.pop();
        }

        return left.empty();
    }
};
