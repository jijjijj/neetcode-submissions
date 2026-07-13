class Solution {
public:
    bool isAnagram(string s, string t) {
        int chars[26] = {};

        for (char c : s) ++chars[c - 'a'];
        for (char c : t) --chars[c - 'a'];
        for (int x : chars) {
            if (x) return false;
        }
        return true;
    }
};
