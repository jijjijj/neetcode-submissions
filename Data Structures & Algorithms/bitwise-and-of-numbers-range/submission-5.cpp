class Solution {
public:
    // +2^(i+1)
    // +shift both until equal
    // remove rightmost set bit until equal
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right &= (right - 1);
        }
        return right;
    }
};