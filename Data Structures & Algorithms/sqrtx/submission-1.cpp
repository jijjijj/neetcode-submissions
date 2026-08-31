class Solution {
public:
    int mySqrt(int x) {
        long long l = 0;
        long long r = x;

        while (l <= r) {
            const long long mid = l + (r - l) / 2;
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