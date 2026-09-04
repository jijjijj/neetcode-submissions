class Solution {
public:
    // +understand why hashset works
    // hashset
    // +hashmap
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> hs;

        for (int i = 0; i < nums.size(); ++i) {
            if (hs.contains(nums[i])) return true;

            if (i >= k) {
                hs.erase(nums[i - k]);
            }

            hs.emplace(nums[i]);
        }

        return false;
    }
};