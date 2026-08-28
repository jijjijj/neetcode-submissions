class Solution {
public:
    // +find_max
    // +heap
    // rec
    string longestDiverseString(int a, int b, int c) {
        return rec(a, b, c, 'a', 'b', 'c');
    }

private:
    std::string rec(int f1, int f2, int f3,
        char c1, char c2, char c3) {
        if (f1 < f2) return rec(f2, f1, f3, c2, c1, c3);
        if (f2 < f3) return rec(f1, f3, f2, c1, c3, c2);

        if (!f2) {
            return std::string(std::min(f1, 2), c1);
        }

        const int cnt1 = std::min(f1, 2);
        std::string res(cnt1, c1);
        const int cnt2 = f1 - cnt1 >= f2 ? 1 : 0;
        res += std::string(cnt2, c2);

        res += rec(f1 - cnt1, f2 - cnt2, f3, c1, c2, c3);
        return res;
    }
};