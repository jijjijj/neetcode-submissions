class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i = !n;

        while (n & (n - 1)) {
            ++i;
            n &= n - 1;
        }

        return i;
    }
};
