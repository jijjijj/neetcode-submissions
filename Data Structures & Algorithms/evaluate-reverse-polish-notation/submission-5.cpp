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

        return compute(tokens, operations);
    }

private:
    int compute(std::vector<std::string>& tokens,
        std::unordered_map<std::string,
            std::function<int(int, int)>>& operations) {
        const std::string tok = tokens.back();
        tokens.pop_back();
        if (operations.contains(tok)) {
            const int b = compute(tokens, operations);
            const int a = compute(tokens, operations);

            return operations[tok](a, b);
        } else {
            return std::stoi(tok);
        }
    }
};
