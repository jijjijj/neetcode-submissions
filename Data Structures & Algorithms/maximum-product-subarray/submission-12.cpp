class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = std::numeric_limits<int>::min();
        
        std::vector<int> suffix(nums.size() + 1);

        for (int i = nums.size() - 1; i >= 0; --i) {
            const int prev = suffix[i + 1] ? suffix[i + 1] : 1;
            suffix[i] = nums[i] * prev;
        }

        int prefix = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix = prefix ? prefix * nums[i] : nums[i];

            res = std::max({ res, prefix, suffix[i] });
        }

        return res;
    }
};
