class Solution {
public:
    // +2^(i+1)
    // shift both until equal
    // remove rightmost set bit until equal
    int rangeBitwiseAnd(int left, int right) {
        int i = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            ++i;
        }
        return left << i;
    }
};