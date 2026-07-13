class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix(nums.size(), 0);

        int mult = 1;
        for (size_t i = 0; i < nums.size(); ++i) {
            prefix[i] = mult;
            mult *= nums[i];
        }

        mult = 1;
        for (size_t i = nums.size(); i > 0; --i) {
            int val = prefix[i - 1] * mult;
            mult *= nums[i - 1];
            nums[i - 1] = val;
        }

        return nums;
    }
};
