class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2) return false;

        std::unordered_set<int> dp;

        dp.emplace(0);

        for (int i = 0; i < nums.size(); ++i) {
            std::unordered_set<int> copy;

            for (int n : dp) {
                if (n + nums[i] == (sum >> 1)) return true;

                copy.emplace(nums[i]);
                copy.emplace(nums[i] + n);
            }

            dp = std::move(copy);
        }

        return false;
    }
};
