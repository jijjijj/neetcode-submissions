class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();

        std::vector<int> suffix(nums.size() + 1);
        std::unordered_map<int, int> mp2; // suffix, count

        mp2[0] = 1;

        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + nums[i];
            ++mp2[suffix[i]];
        }

        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (k)
            cnt += mp2[suffix[i] - k];
            else
            cnt += !suffix[i];
        }

        return cnt;
    }
};