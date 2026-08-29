class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mx = std::numeric_limits<int>::min();

        for (int i = 0; i < nums.size(); ++i) {
            mx = std::max(mx, calc(nums, i));
        }

        return mx;
    }

private:
    int calc(const std::vector<int> nums, int off) {
        int max = std::numeric_limits<int>::min();
        int since = 0;
        int cur = 0;
        for (int i = 0; i < nums.size() * 2; ++i) {
            const int c = (off + i) % nums.size();
            if (cur < 0) {
                cur = 0;
                since = i;
            }
            if (i - since >= nums.size()) break;
            cur += nums[c];
            max = std::max(cur, max);
        }

        return max;
    }
};