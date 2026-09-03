class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ranges::sort(nums);

        std::vector<std::vector<int>> res;

        std::unordered_set<int> mp;
        int zeroes = 0;
        for (int i = 0; i < nums.size(); ++i)
            mp.emplace(nums[i]), zeroes += !nums[i];

        if (zeroes >= 3) res.push_back({ 0, 0, 0 });

        for (int i = 0; i < nums.size(); ++i) {
            mp.erase(nums[i]);
            if (nums[i] > 0) break;
            if (i && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); ++j) {
                mp.erase(nums[j]);
                if (nums[i] + nums[j] > 0) break;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                const long long val = -(nums[i] + nums[j]);
                if (mp.contains(val)) {
                    res.emplace_back(std::vector<int>{
                        nums[i], nums[j], (int)val
                    });
                }
            }

            for (int j = i + 1; j < nums.size(); ++j) mp.emplace(nums[j]);
        }

        return res;
    }
};
