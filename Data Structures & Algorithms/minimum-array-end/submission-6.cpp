class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long x_i = 1;
        long long n_i = 1;

        while (n_i <= n) {
            if ((x_i & x) == 0) {
                if ((n_i & (n - 1))) {
                    ans |= x_i;
                }
                n_i <<= 1;
            }

            x_i <<= 1;
        }

        return ans;
    }
};