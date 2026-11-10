class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = std::numeric_limits<int>::min();
        
        int l = 0;
        int product = 1;
        int negs = 0;
        for (int i = 0; i < nums.size(); ++i) {
            negs += (nums[i] < 0);
            product = product ? product * nums[i] : nums[i];

            if ((i == nums.size() - 1 || !nums[i + 1]) &&
                (negs % 2)) {
                int j = l;
                int p = product;
                while (j < i && p < 0) {
                    p /= nums[j];
                    ++j;
                }
                res = std::max(p, res);

                j = i;
                p = product;
                while (j > l && p < 0) {
                    p /= nums[j];
                    --j;
                }
                res = std::max(p, res);

                l = i + 2;
                negs = 0;
            }

            res = std::max(product, res);
        }

        return res;
    }
};
