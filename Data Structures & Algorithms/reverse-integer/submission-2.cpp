class Solution {
public:
    int reverse(int x) {
        int sign = x >= 0 ? 1 : -1;

        int ans = 0;
        while (x) {
            if (std::numeric_limits<int>::max() / 10 < ans) return 0;
            if (std::numeric_limits<int>::min() / 10 > ans) return 0;
            ans *= 10;
            ans += (x % 10);
            x /= 10;
        }

        return ans;
    }
};
