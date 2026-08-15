class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        // res.push_back({}); // seed

        const int power = (1 << nums.size());

        for (int i = 0; i < power; ++i) {
            std::vector<int> subset;
            for (int j = 0; j < 32; ++j) {
                const bool take = (i >> j) & 1;

                if (take) subset.emplace_back(nums[j]);
            }
            res.emplace_back(std::move(subset));
        }

        return res;
    }
};
