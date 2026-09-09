class Solution {
public:
    long long minEnd(int n, int x) {
        --n;

        int right = 32;
        int left = 0;
        int nleft = 0;
        int nright = 32;

        for (int i = 0; i < 32; ++i) {
            if (x & (1 << i)) {
                right = std::min(i, right);
                left = i;
            }
            
            if (n & (1 << i)) {
                nleft = i;
                nright = std::min(i, nright);
            }
        }

        int mask = 0;
        for (int i = 0; i < right; ++i) {
            mask |= 1;
            mask <<= 1;
        }

        long long ans = mask & n;
        ans |= (x << (right));
        ans |= (n & (~mask)) << (left - right + 1);
        return ans;
    }
};