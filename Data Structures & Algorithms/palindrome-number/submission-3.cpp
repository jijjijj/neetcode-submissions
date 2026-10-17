class Solution {
public:
    bool isPalindrome(int x) {
        long long mul = 0;

        int orig = x;
        while (x) {
            mul *= 10;
            mul += (x % 10);
            x /= 10;
        }

        return std::abs(mul) == orig;
    }
};