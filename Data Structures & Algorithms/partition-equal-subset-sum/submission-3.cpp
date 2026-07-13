class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2) return false;

        std::vector<bool> dp_last(sum + 1);
        std::vector<bool> dp_prev(sum + 1);

        dp_prev[0] = dp_last[0] = true;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 1; j <= sum; ++j) {
                dp_last[j] = dp_prev[j];
                if (nums[i] <= j) dp_last[j] =
                    dp_last[j] | dp_prev[j - nums[i]];

                if ((j == sum / 2) && dp_last[j]) return true;
            }
            std::swap(dp_last, dp_prev);
        }

        return false;
    }
};
