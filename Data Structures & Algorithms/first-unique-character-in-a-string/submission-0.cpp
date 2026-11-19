class Solution {
public:
    int firstUniqChar(string s) {
        std::vector<int> mp(26);

        for (const char c : s) ++mp[c - 'a'];

        for (int i = 0; i < s.size(); ++i) {
            const char c = s[i];
            if (mp[c - 'a'] == 1) return i;
        }

        return -1;
    }
};