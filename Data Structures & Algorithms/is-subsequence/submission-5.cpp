class Solution {
public:
    bool isSubsequence(string s, string t) {
        std::vector<std::vector<int>> mp(t.size() + 1,
            std::vector<int>(256, 10001));

        for (int i = 0; i < t.size() + 1; ++i) {
            if (i) mp[i] = mp[i - 1];
            if (i < t.size()) mp[i][t[i]] = i;
        }

        int i = t.size();
        for (int j = s.size() - 1; j >= 0; --j) {
            if (mp[i][s[j]] >= i) return false;
            i = mp[i][s[j]];
        }

        return true;
    }
};