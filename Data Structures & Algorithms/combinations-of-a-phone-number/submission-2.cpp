class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::unordered_map<char, std::string> mp = {
            { '2', "abc" }, { '3', "def" },
            { '4', "ghi" }, { '5', "jkl" },
            { '6', "mno" }, { '7', "pqrs" },
            { '8', "tuv" }, { '9', "wxyz" }
        };

        std::vector<std::string> res;

        std::string cur;
        dfs(res, 0, mp, cur, digits);

        return res;
    }

private:
    void dfs(
        std::vector<std::string>& res,
        int i, std::unordered_map<char, std::string>& mp,
        std::string& cur,
        const std::string& dg) {
        if (i == dg.size()) {
            if (cur.size()) res.emplace_back(cur);
            return;
        }

        for (const char c : mp[dg[i]]) {
            cur.push_back(c);
            dfs(res, i + 1, mp, cur, dg);
            cur.pop_back();
        }
    }
};
