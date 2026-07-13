class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ranges::sort(nums);

        std::unordered_map<int, int> freq;
        for (int val : nums) ++freq[val];

        std::vector<std::vector<int>> result;
        const int n = nums.size();

        for (int i = 0; i < n; ++i) {
            --freq[nums[i]];
            
            if (i && nums[i] == nums[i - 1]) continue;


            for (int j = i + 1; j < n; ++j) {
                --freq[nums[j]];
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                const int target = -(nums[i] + nums[j]);
                if (freq[target]) {
                    result.emplace_back(std::vector<int>{ nums[i], nums[j], target });
                }
            }

            for (int j = i + 1; j < n; ++j) ++freq[nums[j]];
        }

        return result;
    }
};
