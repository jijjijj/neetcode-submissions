class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int rem = 0;

        for (int i = 0; i < 32; ++i) {
            const int b1 = a & 1;
            const int b2 = b & 1;

            ans |= (((b1 ^ b2 ^ rem)) << i);
            rem = (b1 & b2) | (b1 & rem) | (b2 & rem);
            a >>= 1;
            b >>= 1;
        }

        return ans;
    }
};
