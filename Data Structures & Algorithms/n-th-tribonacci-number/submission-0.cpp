class Solution {
public:
    int tribonacci(int n) {
        std::array<int, 3> t = { 0, 1, 1 };

        if (n <= 2) return t[n];

        for (int i = 3; i <= n; ++i) {
            const int nw = t[0] + t[1] + t[2];
            t[0] = t[1];
            t[1] = t[2];
            t[2] = nw;
        }

        return t.back();
    }
};