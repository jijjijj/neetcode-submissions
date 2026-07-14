class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            const int need = target - numbers[i];
            const auto it = std::ranges::lower_bound(numbers,
                need);

            if (it != numbers.end() && *it == need) 
                return { i + 1, (int)(it - numbers.begin()) + 1 };
        }

        return { -1, -1 };
    }
};
