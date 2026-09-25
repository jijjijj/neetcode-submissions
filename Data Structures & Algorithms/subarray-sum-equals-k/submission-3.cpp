class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();

        std::vector<int> suffix(nums.size() + 1);
        std::vector<std::unordered_map<int, int>>
            mp2(nums.size() + 1); // suffix, count

        mp2.back() = { { 0, 1 }};

        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + nums[i];
            mp2[i] = mp2[i + 1];
            ++mp2[i][suffix[i]];
        }

        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            cnt += mp2[i + 1][suffix[i] - k];
            // cnt -= !k;
        }

        return cnt;
    }
};