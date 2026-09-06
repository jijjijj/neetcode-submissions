class Solution {
public:
    int integerBreak(int n) {
        int ans = 1;

        while (n > 4) {
            ans *= 3;
            n -= 3;
        }

        ans *= n;

        return ans;
    }
};