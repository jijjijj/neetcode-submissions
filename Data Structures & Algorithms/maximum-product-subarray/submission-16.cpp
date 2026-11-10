class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = std::numeric_limits<int>::min();
        
        for (int i = 0; i < nums.size(); ) {
            if (!nums[i]) {
                res = std::max(0, res);
                ++i;
                continue;
            }

            int l = i;
            int product = 1;
            int negs = 0;
            while (i < nums.size() && nums[i]) {
                product *= nums[i];
                negs += (nums[i] < 0);
                ++i;
            }

            if (negs % 2) {
                int j = l;
                int p = product;
                while (j < i - 1 && p < 0) {
                    p /= nums[j];
                    ++j;
                }
                res = std::max(p, res);

                j = i - 1;
                p = product;
                while (j > l && p < 0) {
                    p /= nums[j];
                    --j;
                }
                res = std::max(p, res);
            }

            res = std::max(product, res);
        }

        return res;
    }
};
