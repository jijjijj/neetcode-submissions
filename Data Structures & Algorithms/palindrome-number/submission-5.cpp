class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long rev = 0;

        while (x > rev) {
            rev = (rev * 10) + (x % 10);
            x /= 10;
        }

        return rev == x || (rev / 10 == x);
    }
};