class Solution {
public:
    // understand why hashset works
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i) {
            if (mp.contains(nums[i]) && mp[nums[i]] >= i - k) return true;
            
            mp[nums[i]] = i;
        }

        return false;
    }
};