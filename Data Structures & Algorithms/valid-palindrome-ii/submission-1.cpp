class Solution {
public:
    bool validPalindrome(string s) {
        return dfs(0, s.size() - 1, s, 1);
    }

private:
    bool dfs(int l, int r, const std::string& s, int k) {
        while (l <= r) {
            if (s[l] != s[r]) {
                if (k > 0) {
                    return isPalindrome(l + 1, r, s) ||
                        isPalindrome(l, r - 1, s);
                } else return false;
            }
            ++l;
            --r;
        }

        return true;
    }

    bool isPalindrome(int l, int r, const std::string& s) {
        while (l <= r) {
            if (s[l++] != s[r--]) return false;
        }

        return true;
    }
};