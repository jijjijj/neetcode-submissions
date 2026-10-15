class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return check(s, t) && check(t, s);
    }

private:
    bool check(const std::string& s,
        const std::string& t) {
        std::unordered_map<char, char> mp;

        for (int i = 0; i < s.size(); ++i) {
            const char a = s[i];
            const char b = t[i];

            if (mp.contains(a) && mp[a] != b) return false;

            mp[a] = b;
        }

        return true;
    }
};