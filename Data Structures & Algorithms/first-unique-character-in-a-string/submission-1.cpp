class Solution {
public:
    int firstUniqChar(string s) {
        const int n = s.size();

        std::vector<int> mp(26, n + 1);

        for (int i = 0; i < s.size(); ++i) {
            const int ind = s[i] - 'a';
            if (mp[ind] == n + 1) {
                mp[ind] = i;
            } else {
                mp[ind] = n;
            }
        }

        int res = n;
        for (const int v : mp) {
            res = std::min(v, res);
        }

        return res == n ? -1 : res;
    }
};