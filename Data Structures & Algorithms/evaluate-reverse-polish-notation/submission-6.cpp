class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::unordered_map<std::string,
            std::function<int(int, int)>> operations = {
            { "+", [](const int& a, const int& b) { return a + b; }},
            { "-", [](const int& a, const int& b) { return a - b; }},
            { "*", [](const int& a, const int& b) { return a * b; }},
            { "/", [](const int& a, const int& b) { return a / b; }},
        };

        int ans = 0;

        std::list<std::string> toks(tokens.begin(), tokens.end());

        for (auto it = toks.begin(); it != toks.end(); ++it) {
            if (operations.contains(*it)) {
                const int a = std::stoi(*std::prev(std::prev(it)));
                const int b = std::stoi(*std::prev(it));

                *it = std::to_string(operations[*it](a, b));
                toks.erase(std::prev(std::prev(it)), it);
            }

            ans = std::stoi(*it);
        }

        return ans;
    }
};
