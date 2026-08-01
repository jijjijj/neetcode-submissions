class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res = 1;
        for (int i = m, j = 1; i < m + n - 1; ++i, ++j) {
            res *= i;
            res /= j;
        }
        return res;
    }
};
