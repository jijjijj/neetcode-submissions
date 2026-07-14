class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while (l < r) {
            const int sum = numbers[l] + numbers[r];

            if (sum > target) {
                --r;
            } else if (sum < target) {
                ++l;
            } else {
                return {
                    std::min(l, r) + 1,
                    std::max(l, r) + 1
                };
            }
        }

        return { -1, -1 };
    }
};
