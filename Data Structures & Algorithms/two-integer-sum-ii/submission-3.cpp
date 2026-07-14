class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::unordered_map<int, int> mp;

        for (int i = 0; i < numbers.size(); ++i) {
            const int need = target - numbers[i];
            if (mp.contains(need)) {
                return { mp[need] + 1, i + 1 };
            }

            mp[numbers[i]] = i;
        }

        return { -1, -1 };
    }
};
