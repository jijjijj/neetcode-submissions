class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        std::ranges::sort(nums);

        const int total = std::accumulate(nums.begin(), nums.end(), 0);
        if (total % k) return false;

        std::vector<int> subsets(k, 0);

        return can(0, nums, k, subsets, total / k);
    }

private:
    bool can(int i, const vector<int>& nums, int k,
        std::vector<int>& subsets, int target) {

        if (i >= nums.size()) {
            bool finished = true;
            for (int j = 1; j < k; ++j) {
                if (subsets[j] != subsets[j - 1]) {
                    finished = false;
                    break;
                }
            }

            return finished;
        }

        for (int j = 0; j < k; ++j) {
            if (subsets[j] + nums[i] > target) continue;
            
            subsets[j] += nums[i];
            if (can(i + 1, nums, k, subsets, target)) return true;
            subsets[j] -= nums[i];

            if (!subsets[j]) break;
        }

        return false;
    }
};