class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;

        if (n % 8 == 7) return 4;

        if (is_square(n)) return 1;

        for (int i = 1; i * i < n; ++i) {
            if (is_square(n - i * i)) return 2;
        }

        return 3;
    }

private:
    bool is_square(int v) {
        const int sq = std::sqrt(v);
        return sq * sq == v;
    }
};