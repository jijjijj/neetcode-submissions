class Solution {
public:
    int op(int a, int b, char tok) const {
        switch (tok) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }

        throw std::invalid_argument{ "" };
    }

    int evalRPN(vector<string>& tokens) {
        std::stack<int> operands;

        for (const auto& tok : tokens) {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                const int a = operands.top();
                operands.pop();
                const int b = operands.top();
                operands.pop();
                operands.push(op(b, a, tok[0]));
            } else {
                operands.push(std::stoi(tok));
            }
        }

        return operands.top();
    }
};
