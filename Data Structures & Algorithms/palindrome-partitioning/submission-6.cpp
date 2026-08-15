class Solution {
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);

        return res;
    }

private:
    void dfs(const std::string& s, int i) {
        if (i == s.size()) {
            res.emplace_back(cur);
            return;
        }

        for (int j = i; j < s.size(); ++j) {
            int l = i;
            int r = j;

            bool pal = true;
            while (l < r) {
                if (s[l] != s[r]) {
                    pal = false;
                    break;
                }

                ++l;
                --r;
            }

            if (pal) {
                cur.emplace_back(
                    s.substr(i, j - i + 1));
                dfs(s, j + 1);
                cur.pop_back();
            }
        }
    }

    std::vector<std::string> cur;
    std::vector<std::vector<string>> res;
};
