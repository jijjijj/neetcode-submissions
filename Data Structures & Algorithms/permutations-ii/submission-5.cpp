class Solution {
public:
    // +hash map
    // +optimal
    // +hashset/boolarray
    // next permutation
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        const int n = nums.size();

        vector<vector<int>> res;
        std::ranges::sort(nums);
        res.emplace_back(nums);

        while (true) {
            int i = n - 2;
            while (i >= 0 &&
                nums[i] >= nums[i + 1]) --i;

            if (i < 0) break;

            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) --j;

            std::swap(nums[i], nums[j]);
            std::reverse(nums.begin() + i + 1, nums.end());
            res.emplace_back(nums);
        }

        return res;
    }
};