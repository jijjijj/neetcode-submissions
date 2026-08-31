class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;

        while (l <= r) {
            const int mid = l + (r - l) / 2;
            const long long sq = mid * mid;

            if (sq <= x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return r;
    }
};