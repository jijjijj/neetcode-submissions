class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int min = std::numeric_limits<int>::max();
        int cur = 0;

        for (int r = 0; r < nums.size(); ++r) {
            cur += nums[r];

            while (l <= r && cur >= target) {
                min = std::min(r - l + 1, min);
                cur -= nums[l++];
            }
        }

        return min == std::numeric_limits<int>::max() ? 0 : min;
    }
};