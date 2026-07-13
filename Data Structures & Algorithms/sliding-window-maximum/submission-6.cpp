class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();

        std::vector<int> result;
        result.reserve(n - k);

        std::vector<int> left_max;
        left_max.reserve(n);
        std::vector<int> right_max;
        right_max.reserve(n);

        for (int i = 0; i < n; ++i) {
            left_max[i] = (i % k)
                ? std::max(left_max[i - 1], nums[i])
                : nums[i];
        }

        right_max[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = (i % k)
                ? std::max(right_max[i + 1], nums[i])
                : nums[i];
        }

        for (int i = k - 1; i < n; ++i) {
            result.emplace_back(std::max(
                right_max[i - k + 1], left_max[i]));
        } 

        return result;
    }
};
