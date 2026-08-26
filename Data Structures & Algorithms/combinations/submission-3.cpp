class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb(k, 0);
        int i = 0;

        while (i >= 0) {
            ++comb[i];
            if (comb[i] > n) {
                --i;
                continue;
            }

            if (i == k - 1) {
                res.emplace_back(comb);
            } else {
                ++i;
                comb[i] = comb[i - 1];
            }
        }

        return res;
    }
};