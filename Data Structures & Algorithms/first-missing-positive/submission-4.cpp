class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();

        for (int& v : nums) {
            if (v < 0) v = 0;
        }

        for (int i = 0; i < n; ++i) {
            const int val = std::abs(nums[i]);

            if (val > 0 && val <= n) {
                if (nums[val - 1] > 0) {
                    nums[val - 1] *= -1;
                } else {
                    nums[val - 1] = -n - 1;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 0) return i + 1;
        }

        return n + 1;
    }
};