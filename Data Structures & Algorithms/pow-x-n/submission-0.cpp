class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            n = -n;
            x = 1.0 / x;
        }
        if (n == 0) return 1.0;
        if (n == 1) return x;

        double r = myPow(x, n / 2);
        r *= r;
        if (n & 1) {
            r *= x;
        }
        return r;

        // pow(x, n) = if (n % 2 == 0) pow(x, n / 2) * pow(x, n / 2)
    }
};
