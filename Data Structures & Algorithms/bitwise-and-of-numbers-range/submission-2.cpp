class Solution {
public:
    // 2^(i+1)
    // shift both until equal
    // remove rightmost set bit until equal
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (!(left & (1 << i))) continue;

            long rem = (left % (1 << i));
            if (left - rem + 0ll + (1 << i) > right) {
                res |= (1 << i);
            }
        }
        return res;
    }
};