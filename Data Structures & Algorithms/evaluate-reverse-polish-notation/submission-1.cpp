class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> operands;

        int result = 0;

        for (const auto& tok : tokens) {
            if (tok == "+") {
                const int a = operands.top();
                operands.pop();
                const int b = operands.top();
                operands.pop();
                operands.push(a + b);
            } else if (tok == "-") {
                const int a = operands.top();
                operands.pop();
                const int b = operands.top();
                operands.pop();
                operands.push(b - a);
            } else if (tok == "*") {
                const int a = operands.top();
                operands.pop();
                const int b = operands.top();
                operands.pop();
                operands.push(b * a);
            } else if (tok == "/") {
                const int a = operands.top();
                operands.pop();
                const int b = operands.top();
                operands.pop();
                operands.push(b / a);
            } else {
                operands.push(std::stoi(tok));
            }
        }

        return operands.top();
    }
};
