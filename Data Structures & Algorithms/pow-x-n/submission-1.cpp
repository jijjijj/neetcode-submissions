class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            n = -n;
            x = 1.0 / x;
        }
        if (n == 0) return 1.0;
        if (n == 1) return x;

        double res = 1.0;
        while (n > 1) {
            if (n & 1) {
                res *= x;
            }

            x *= x;
            n >>= 1;
        }

        return res * x;
    }
};
