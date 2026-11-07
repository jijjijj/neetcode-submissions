class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = 0;
        int pos = 1;
        int neg = 1;

        for (const int v : nums) {
            pos = std::max({ v, pos * v, neg * v });
            neg = std::min({ v, neg * v, pos * v });
            res = std::max({ res, pos, neg });
        }

        return res;
    }
};
