class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> res(n + 1);

        for (int i = 0; i <= n; ++i) {
            int j = 0;
            int x = i;
            while (x) {
                ++j;
                x &= (x - 1);
            }
            res[i] = j;
        }

        return res;
    }
};
