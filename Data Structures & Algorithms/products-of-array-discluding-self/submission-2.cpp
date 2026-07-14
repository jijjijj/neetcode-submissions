class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> right(nums.size());

        int cur = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            right[i] = cur;
            cur *= nums[i];
        }

        cur = 1;

        for (int i = 0; i < nums.size(); ++i) {
            const int tmp = nums[i];
            nums[i] = cur * right[i];
            cur *= tmp;
        }

        return nums;
    }
};
