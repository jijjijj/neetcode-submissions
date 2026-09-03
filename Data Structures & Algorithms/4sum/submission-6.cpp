class Solution {
public:
    // +k-1 loops + map
    // k-2 loops + two pointer
    // two pointer + recursion
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::ranges::sort(nums);

        std::vector<std::vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r) {
                    const long long cur = nums[i] + nums[j] + 0ll +
                        nums[l] + nums[r];
                    if (cur == target) {
                        res.emplace_back(std::vector<int>{
                            nums[i], nums[j], nums[l], nums[r]
                        });
                        ++l;
                        --r;
                        while (l < r && nums[l] == nums[l - 1]) ++l;
                        while (l < r && nums[r] == nums[r + 1]) --r;
                    } else if (cur > target) {
                        --r;
                    } else {
                        ++l;
                    }
                }
            }
        }
        return res;
    }
};