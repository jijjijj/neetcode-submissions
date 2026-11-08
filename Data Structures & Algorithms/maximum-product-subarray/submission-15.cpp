class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = std::numeric_limits<int>::min();
        
        int l = 0;
        int prefix = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix = prefix ? prefix * nums[i] : nums[i];
            res = std::max(prefix, res);

            if (!nums[i]) l = i + 1;

            if (i == nums.size() - 1 || !nums[i + 1]) {
                while (l < i) {
                    prefix /= nums[l];
                    ++l;
                    res = std::max(prefix, res);
                }
            }
        }

        return res;
    }
};
