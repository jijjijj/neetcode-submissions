class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::ranges::sort(nums);

        std::vector<std::vector<int>> result;
        result.emplace_back(std::vector<int>{});

        int start = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (!i || nums[i] != nums[i - 1]) start = 0;
            
            const int n = result.size();
            for (int j = start; j < n; ++j) {
                std::vector<int> sub = result[j];
                sub.emplace_back(nums[i]);
                result.emplace_back(std::move(sub));
            }

            start = n;
        }

        return result;
    }
};
