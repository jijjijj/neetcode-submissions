class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;
        mp[0] = -1;

        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur += nums[i];

            const int r = cur % k;

            if (const auto it = mp.find(r); it == mp.end()) {
                mp[r] = i;
            } else if (i - it->second > 1) {
                return true;
            }
        }

        return false;
    }
};