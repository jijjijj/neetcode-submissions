class Solution {
public:
    bool isAnagram(string s, string t) {
        int chars[26] = {};

        for (char c : s) ++chars[c - 'a'];
        for (char c : t) {
            if (--chars[c - 'a'] < 0) return false;
        }

        return true;
    }
};
