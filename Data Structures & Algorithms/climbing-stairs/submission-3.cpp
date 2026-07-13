class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> res = {1, 0, 0, 1};
        std::vector<int> m = {1, 1, 1, 0};

        while (n) {
            if (n & 1) mult(res, m);
            mult(m, m);
            n >>= 1;
        }
        
        return res[0];
    }

    void mult(std::vector<int>& out, const std::vector<int>& b) const {
        int na = out[0] * b[0] + out[1] * b[2];
        int nb = out[0] * b[1] + out[1] * b[3];
        int nc = out[2] * b[0] + out[3] * b[2];
        int nd = out[2] * b[1] + out[3] * b[3];
        out = { na, nb, nc, nd };
    }
};
