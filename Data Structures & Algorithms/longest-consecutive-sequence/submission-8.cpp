class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> mp;

        int max = 0;

        for (int i = 0; i < nums.size(); ++i) {
            mp.emplace(nums[i]);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!mp.contains(nums[i] - 1)) {
                int j = nums[i];
                int len = 0;
                while (mp.contains(j)) {
                    ++j;
                    ++len;
                }

                max = std::max(max, len);
            }
        }

        return max;
    }
};
