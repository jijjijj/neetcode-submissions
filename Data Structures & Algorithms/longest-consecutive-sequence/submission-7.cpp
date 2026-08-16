class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> mp;

        int max = 0;

        for (int i = 0; i < nums.size(); ++i) {
            const int val = nums[i];

            if (mp[val]) continue;

            // 1 2
            // 1: 2
            // 2: 2
            mp[val] += mp[val - 1] + 1 + mp[val + 1];
            mp[val - mp[val - 1]] = mp[val];
            mp[val + mp[val + 1]] = mp[val];

            max = std::max(max, mp[val]);
        }

        return max;
    }
};
