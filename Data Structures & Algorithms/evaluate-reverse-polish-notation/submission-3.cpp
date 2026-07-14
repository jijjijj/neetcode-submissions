class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> ops;

        std::unordered_map<std::string,
            std::function<int(int, int)>> operations = {
            { "+", [](const int& a, const int& b) { return a + b; }},
            { "-", [](const int& a, const int& b) { return a - b; }},
            { "*", [](const int& a, const int& b) { return a * b; }},
            { "/", [](const int& a, const int& b) { return a / b; }},
        };

        for (const auto& tok : tokens) {
            if (operations.contains(tok)) {
                const int b = ops.top(); ops.pop();
                const int a = ops.top(); ops.pop();

                ops.push(operations[tok](a, b));
            } else {
                ops.push(std::stoi(tok));
            }
        }

        return ops.top();
    }
};
