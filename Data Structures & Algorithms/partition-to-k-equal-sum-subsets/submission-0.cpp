class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // std::ranges::sort(nums);

        std::vector<int> subsets(k, 0);

        return can(0, nums, k, subsets);
    }

private:
    bool can(int i, const vector<int>& nums, int k,
        std::vector<int>& subsets) {
        bool finished = true;
        for (int j = 1; j < k; ++j) {
            if (subsets[j] != subsets[j - 1]) {
                finished = false;
                break;
            }
        }

        if (i >= nums.size() && finished) return true;
        if (i >= nums.size()) return false;

        for (int j = 0; j < k; ++j) {
            subsets[j] += nums[i];
            if (can(i + 1, nums, k, subsets)) return true;
            subsets[j] -= nums[i];

            if (!subsets[j]) break;
        }

        return false;
    }
};