class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mult = 1;
        int zeroes = 0;

        for (int n : nums) {
            if (n != 0) mult *= n;
            else ++zeroes;
        }

        if (zeroes > 1) return std::vector<int>(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = nums[i] ? ((!zeroes) * mult / nums[i]) : mult;
        }

        return nums;
    }
};
