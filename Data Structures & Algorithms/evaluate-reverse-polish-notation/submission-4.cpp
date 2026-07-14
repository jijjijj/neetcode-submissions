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

        int i = tokens.size() - 1;
        return compute(tokens, i, operations);
    }

private:
    int compute(const std::vector<std::string>& tokens,
        int& i, std::unordered_map<std::string,
            std::function<int(int, int)>>& operations) {
        const std::string tok = tokens[i--];
        if (operations.contains(tok)) {
            const int b = compute(tokens, i, operations);
            const int a = compute(tokens, i, operations);

            return operations[tok](a, b);
        } else {
            return std::stoi(tok);
        }
    }
};
