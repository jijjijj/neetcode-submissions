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
                const int first = vals[l].second;
                const int second = vals[r].second;
                return first <= second ? std::vector<int>{ first, second } : std::vector<int>{second, first};
            }
        }

        return { -1, -1 };
    }
};
