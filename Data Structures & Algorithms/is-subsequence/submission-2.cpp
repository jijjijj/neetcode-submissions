class Solution {
public:
    bool isSubsequence(string s, string t) {
        std::vector<std::vector<int>> mp(t.size(),
            std::vector<int>(256));

        for (int i = 0; i < t.size(); ++i) {
            mp[t[i]] = std::min(mp[t[i]], i);
        }

        for (int i = 1; i < s.size(); ++i) {
            if (mp[s[i]] < mp[s[i - 1]]) return false;
        }

        return mp[s[0]] != 101;
    }
};