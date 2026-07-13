class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (!(::tolower(s[left]) <= 'z' && ::tolower(s[left]) >= 'a') &&
                !(s[left] >= '0' && s[left] <= '9')) ++left;
            while (!(::tolower(s[right]) <= 'z' && ::tolower(s[right]) >= 'a') &&
                !(s[right] >= '0' && s[right] <= '9')) --right;

            if (left < right && ::tolower(s[left++]) != ::tolower(s[right--])) return false;
        }

        return true;
    }
};
