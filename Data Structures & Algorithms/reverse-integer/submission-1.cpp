class Solution {
public:
    int reverse(int x) {
        int sign = x >= 0 ? 1 : -1;

        int ans = 0;
        while (x) {
            ans *= 10;
            ans += (x % 10);
            x /= 10;
        }
            if ((ans >= 0 && sign == -1) ||
                (ans < 0 && sign == 1)) return 0;
        return ans;
    }
};
