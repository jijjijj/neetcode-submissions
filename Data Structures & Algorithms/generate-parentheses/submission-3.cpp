class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::vector<std::string>> result(n + 1);
        result[0] = {""};

        for (int k = 0; k <= n; ++k) {
            for (int i = 0; i < k; ++i) {
                for (const auto& left : result[i]) {
                    for (const auto& right : result[k - i - 1]) {
                        result[k].emplace_back("(" + left + ")" + right);
                    }
                }
            }
        }

        return result[n];
    }
};
