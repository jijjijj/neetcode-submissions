class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> map;

        for (int x : nums)
        {
            if (map[x]++)
            {
                return true;
            }
        }

        return false;
    }
};