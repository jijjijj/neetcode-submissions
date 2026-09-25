class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();

        std::unordered_map<int, int> mp2; // suffix, count

        mp2[0] = 1;

        int cnt = 0;
        int suffix = 0;

        for (int i = n - 1; i >= 0; --i) {
            suffix += nums[i];
            cnt += mp2[suffix - k];
            ++mp2[suffix];
        }

        return cnt;
    }
};