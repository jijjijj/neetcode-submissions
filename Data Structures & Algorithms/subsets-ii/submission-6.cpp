class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::ranges::sort(nums);

        res.push_back({});
        
        int start = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (!i || nums[i - 1] != nums[i]) start = 0;

            const int size = res.size();
            for (int j = start; j < size; ++j) {
                std::vector<int> copy = res[j];
                copy.emplace_back(nums[i]);
                res.emplace_back(std::move(copy));
            }
            start = size;
        }

        return res;
    }

    std::vector<std::vector<int>> res;
};
