class Solution {
public:
    long long minEnd(int n, int x) {
        --n;

        long long ans = x;

        for (int i = 0; i < sizeof(ans); ++i) {
            if (!n) break;

            if (!(ans & (1 << i))) {
                ans |= ((n & 1) << i);
                n >>= 1;
            }
        }

        return ans;
    }
};