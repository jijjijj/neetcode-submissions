class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> map;

        for (int x : nums)
        {
            if (!map.emplace(x).second)
            {
                return true;
            }
        }

        return false;
    }
};