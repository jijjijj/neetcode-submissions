class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::vector<std::string>> res(n + 1);
        res[0] = { "" };

        for (int k = 1; k <= n; ++k) {
            for (int i = 0; i < k; ++i) {
                for (const auto& a : res[i]) {
                    for (const auto& b : res[k - i - 1]) {
                        res[k].emplace_back("(" + a + ")" + b);
                    }
                }
            }
        }

        return res[n];
    }
};
