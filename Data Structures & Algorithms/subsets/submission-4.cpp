class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        res.push_back({}); // seed

        for (int i = 0; i < nums.size(); ++i) {
            const size_t size = res.size();
            for (int j = 0; j < size; ++j) {
                std::vector<int> copy = res[j];

                copy.emplace_back(nums[i]);
                res.emplace_back(std::move(copy));
            }
        }

        return res;
    }
};
