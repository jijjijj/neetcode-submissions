class Solution {
public:
    bool isSubsequence(string s, string t) {
        std::vector<std::vector<int>> mp(t.size() + 1,
            std::vector<int>(256, 10001));

        for (int i = 1; i <= t.size(); ++i) {
            mp[i] = mp[i - 1];
            mp[i][t[i - 1]] = i - 1;
        }

        int i = t.size();
        for (int j = s.size() - 1; j >= 0; --j) {
            if (mp[i][s[j]] == 10001) return false;
            i = mp[i][s[j]];
        }

        return true;
    }
};