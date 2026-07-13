class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max = 0;

        std::unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            const int num = nums[i];

            if (!m[num]) {
                m[num] = m[num - 1] + m[num + 1] + 1;
                m[num - m[num - 1]] = m[num];
                m[num + m[num + 1]] = m[num];

                max = std::max(max, m[num]);
            }
        }

        return max;
    }
};
