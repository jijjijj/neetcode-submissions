class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;

        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            const int v = nums[i];
            cur += v;

            const int r = cur % k;

            if (mp.contains(r) && i - mp[r] > 1) return true;

            if (!mp.contains(r)) mp[r] = i;
        }

        return false;
    }
};