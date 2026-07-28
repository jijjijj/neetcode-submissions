class Solution {
public:
    int getSum(int a, int b) {
        for (int i = 0; i < 32; ++i) {
            int carry = (a & b);
            a ^= b;
            b = (carry << 1);
        }
        return a;
    }
};
