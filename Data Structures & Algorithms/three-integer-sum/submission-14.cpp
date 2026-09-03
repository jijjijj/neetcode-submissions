class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ranges::sort(nums);

        std::vector<std::vector<int>> res;

        std::unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) mp[nums[i]] = i;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break;
            if (i && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] > 0) break;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                const long long val = -(nums[i] + nums[j]);
                if (mp.contains(val) && mp[val] > j) {
                    res.emplace_back(std::vector<int>{
                        nums[i], nums[j], (int)val
                    });
                }
            }
        }

        return res;
    }
};
