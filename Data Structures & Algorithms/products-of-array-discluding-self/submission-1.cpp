class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix(nums.size(), 1);

        for (size_t i = 1; i < nums.size(); ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        int mult = 1;
        for (size_t i = nums.size(); i > 0; --i) {
            prefix[i - 1] *= mult;
            mult *= nums[i - 1];
        }

        return prefix;
    }
};
