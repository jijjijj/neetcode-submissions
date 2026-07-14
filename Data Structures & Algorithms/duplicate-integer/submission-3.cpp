class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> mp;

        for (int n : nums) {
            if (mp.contains(n)) return true;

            mp.emplace(n);
        }

        return false;
    }
};