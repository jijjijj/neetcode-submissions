class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // first, last, negatives
        std::vector<std::tuple<int, int, int>> segments;

        int start = 0;
        int negative = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                segments.emplace_back(
                    std::tuple{ start, i, negative });
                start = i + 1;
                negative = 0;
            } else if (nums[i] < 0) ++negative;
        }
        segments.emplace_back(
            std::tuple{ start, nums.size() - 1, negative });

        int max = std::numeric_limits<int>::min();

        for (auto& [start, finish, negs] : segments) {
            int cur = 1;
            
            for (int i = start, j = start; i <= finish; ++i) {
                cur *= nums[i];
                negs -= (nums[i] < 0);

                while (negs < 0 && j <= i) {
                    cur /= nums[j];
                    negs += (nums[j] < 0);
                    ++j;
                }

                max = std::max(max, cur);
            }
        }

        return max;
    }
};
