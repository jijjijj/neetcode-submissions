class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<std::pair<int, int>> vals;
        for (int i = 0; i < nums.size(); ++i)
            vals.emplace_back(std::pair{ nums[i], i });
        std::ranges::sort(vals);

        int l = 0;
        int r = vals.size() - 1;

        while (l <= r) {
            const int sum = vals[l].first + vals[r].first;
            if (sum > target) {
                --r;
            } else if (sum < target) {
                ++l;
            } else {
                return { vals[l].second, vals[r].second };
            }
        }

        return { -1, -1 };
    }
};
