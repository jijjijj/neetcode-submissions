class Solution {
public:
    long long minEnd(int n, int x) {
        --n;

        long long ans = x;

        for (int i = 0; i < sizeof(ans) * 8; ++i) {
            if (!n) break;
            
            if (!(ans & (1llu << i))) {
                ans |= (((long long)(n) & 1ll) << i);
                n >>= 1;
            }
        }

        return ans;
    }
};