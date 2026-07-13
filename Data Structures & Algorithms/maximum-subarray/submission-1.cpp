class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = std::numeric_limits<int>::min();
        int cur = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (cur < 0) {
                cur = nums[i];
            } else {
                cur += nums[i];
            }

            max = std::max(max, cur);
        }

        return max;
    }
};
