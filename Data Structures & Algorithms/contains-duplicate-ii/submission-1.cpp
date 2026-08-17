class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i) {
            if (mp[nums[i]]) return true;
            ++mp[nums[i]];

            if (i >= k) {
                --mp[nums[i - k]];
            }
        }

        return false;
    }
};