class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = std::numeric_limits<int>::min();
        
        int l = 0;
        int prefix = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                prefix = prefix ? prefix * nums[i] : nums[i];
                res = std::max(prefix, res);
            } else {
                while (l < i) {
                    res = std::max(prefix, res);
                    prefix /= nums[l];
                    ++l;
                }
                ++l;
                prefix = 0;
                res = std::max(prefix, res);
            }
        }

        return res;
    }
};
