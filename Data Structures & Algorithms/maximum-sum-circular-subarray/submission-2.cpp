class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max = std::numeric_limits<int>::min();
        int since = 0;
        int cur = 0;
        for (int i = 0; i < nums.size() * 2; ++i) {
            const int c = (i) % nums.size();
            if (i - since >= nums.size()) cur -= nums[since++ % nums.size()];
            if (cur <= 0) {
                cur = 0;
                since = i;
            }
            cur += nums[c];
            max = std::max(cur, max);
        }

        return max;
    }
};