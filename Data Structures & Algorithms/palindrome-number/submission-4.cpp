class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long mul = 1;

        while (mul <= x) mul *= 10;
        mul /= 10;

        while (x) {
            const int left = x / mul;
            const int right = x % 10;

            // std::cout << left << " " << right << std::endl;

            if (left != right) return false;

            x %= mul;
            x /= 10;
            mul /= 100;
        }

        return true;
    }
};