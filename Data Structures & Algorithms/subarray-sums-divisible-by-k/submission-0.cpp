class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;

        std::unordered_map<int, int> mp; //  , cnt
        mp[0] = 1;
        
        int cur = 0;

        for (int i = 0; i < nums.size(); ++i) {
            cur += nums[i];

            cnt += mp[cur % k];

            ++mp[cur % k];
        }

        return cnt;
    }
};