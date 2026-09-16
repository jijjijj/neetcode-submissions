class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long ans_i = 1;
        int nb = 0;

        for (int i = 0; i < 64; ++i) {
            if ((ans_i & x) == 0) {
                if ((1ll << nb++) & (n - 1)) ans |= ans_i;
            }

            ans_i <<= 1;
        }

        return ans;
    }
};