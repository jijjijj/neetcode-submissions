class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::ranges::sort(nums);

        std::unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i) mp[nums[i]] = i;

        std::vector<std::vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            // if (nums[i] > target) break;

            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                // if (nums[i] + nums[j] > target) break;

                for (int k = j + 1; k < nums.size(); ++k) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    // if (nums[i] + nums[j] + nums[k] > target) break;

                    const int looking_for = target -
                        (nums[i] + nums[j] + nums[k]);
                    // std::cout << nums[i] << " " << nums[j] << " " << nums[k] << " " << looking_for << std::endl;
                    if (mp.contains(looking_for) && mp[looking_for] > k) {
                        res.push_back({ nums[i], nums[j], nums[k], looking_for });
                    }
                }
            }
        }
        return res;
    }
};