class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;

        result.emplace_back(std::vector<int>{}); // seed

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = result.size() - 1; j >= 0; --j) {
                std::vector<int> copy = result[j];
                copy.emplace_back(nums[i]);
                result.emplace_back(std::move(copy));
            }
        }

        return result;
    }
};
