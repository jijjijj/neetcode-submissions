class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        std::unordered_map<char, std::string> mp = {
            { '2', "abc" }, { '3', "def" },
            { '4', "ghi" }, { '5', "jkl" },
            { '6', "mno" }, { '7', "pqrs" },
            { '8', "tuv" }, { '9', "wxyz" }
        };

        std::vector<std::string> res;
        res.push_back("");

        for (int i = 0; i < digits.size(); ++i) {
            std::vector<std::string> tmp;

            for (const auto& p : res) {
                for (const char c : mp[digits[i]]) {
                    tmp.emplace_back(p + c);
                }
            }

            res = std::move(tmp);
        }

        return res;
    }
};
