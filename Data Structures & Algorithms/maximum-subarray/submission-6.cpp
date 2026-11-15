class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = std::numeric_limits<int>::min();
        int cur = 0;

        for (const int val : nums) {
            cur = cur < 0 ? val : cur + val;
            mx = std::max(mx, cur);
        }

        return mx;
    }
};
