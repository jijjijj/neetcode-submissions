class Solution {
public:
    int climbStairs(int n) {
        int dp2 = 1;
        int dp1 = 1;

        for (int i = 1; i < n; ++i) {
            const int tmp = dp1 + dp2;
            dp2 = dp1;
            dp1 = tmp;
        }
        
        return dp1;
    }
};
