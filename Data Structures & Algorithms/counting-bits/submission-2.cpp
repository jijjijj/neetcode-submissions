class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> res(n + 1);

        int power = 1;
        for (int i = 1; i <= n; ++i) {
            if (i == power * 2) {
                power = i;
            }
            res[i] = res[i - power] + 1;
        }

        return res;
    }
};
