class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ranges::sort(nums);

        std::vector<std::vector<int>> res;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break;
            if (i && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                const int cur = nums[i] + nums[l] + nums[r];

                if (!cur) {
                    res.emplace_back(std::vector<int>{
                        nums[i], nums[l], nums[r]
                    });
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                } else if (cur > 0) {
                    --r;
                } else {
                    ++l;
                }
            }
        }

        return res;
    }
};
