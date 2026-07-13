class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max = 0;

        std::unordered_map<int, int> present;

        for (int num : nums) {
            if (!present[num]) {
                const int prev = present[num - 1];
                const int next = present[num + 1];
                const int n = present[num] = prev + next + 1;
                present[num - prev] = n;
                present[num + next] = n;

                max = std::max(n, max);
            }
        }

        return max;
    }
};
