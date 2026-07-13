class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ranges::sort(nums);

        std::vector<std::vector<int>> result;
        const int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                const int sum = nums[i] + nums[l] + nums[r];

                if (sum > 0) {
                    --r;
                } else if (sum < 0) {
                    ++l;
                } else {
                    result.emplace_back(std::vector<int>{
                        nums[i], nums[l], nums[r] });
                    ++l; --r;
                }
            }
        }

        return result;
    }
};
