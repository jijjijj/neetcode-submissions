class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max = std::numeric_limits<int>::min();
        int min = std::numeric_limits<int>::max();
        int curMax = 0;
        int curMin = 0;
        int total = 0;

        for (const int val : nums) {
            total += val;
            curMax = std::max(curMax + val, val);
            curMin = std::min(curMin + val, val);
            max = std::max(max, curMax);
            min = std::min(min, curMin);
        }

        return max > 0 ? std::max(max, total - min) : max;
    }
};