class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        if (n % 3 == 0) return std::pow(3, n / 3);
        if (n % 3 == 1) return std::pow(3, (n - 4) / 3) * 4;

        return std::pow(3, (n - 2) / 3) * 2;
    }
};