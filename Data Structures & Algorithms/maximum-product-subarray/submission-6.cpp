class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int suffix = 1;

        int max = std::numeric_limits<int>::min();

        for (int i = 0; i < nums.size(); ++i) {
            prefix = nums[i] * (prefix ? prefix : 1);
            suffix = nums[nums.size() - i - 1] * (suffix ? suffix : 1);

            max = std::max({ max, suffix, prefix });
        }

        return max;
    }
};
