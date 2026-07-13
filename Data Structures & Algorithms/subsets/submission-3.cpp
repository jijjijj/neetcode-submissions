class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;

        for (int i = 0; i < (1 << nums.size()); ++i) {
            std::vector<int> subset;

            int j = 0;
            int n = i;
            while (n) {
                if (n & 1) subset.emplace_back(nums[j]);
                n >>= 1;
                ++j;
            }

            result.emplace_back(std::move(subset));
        }

        return result;
    }
};
