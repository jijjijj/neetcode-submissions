class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max = 0;

        std::unordered_map<int, int> present;

        for (int num : nums) {
            if (!present[num]) {
                present[num] = present[num - 1] + present[num + 1] + 1;
                present[num - present[num - 1]] = present[num];
                present[num + present[num + 1]] = present[num];

                max = std::max(present[num], max);
            }
        }

        return max;
    }
};
