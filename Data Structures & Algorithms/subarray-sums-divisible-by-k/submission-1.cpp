class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;

        std::vector<int> mp(k); //  , cnt
        mp[0] = 1;
        
        int cur = 0;

        for (int i = 0; i < nums.size(); ++i) {
            cur += nums[i];

            int rem = ((cur % k) + k) % k;

            cnt += mp[rem];

            ++mp[rem];
        }

        return cnt;
    }
};