class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int l = mySqrt(x / 4) * 2;
        int r = l + 1;

        return r * r <= x ? r : l;
    }
};