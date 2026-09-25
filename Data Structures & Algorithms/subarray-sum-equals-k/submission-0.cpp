class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();

        std::vector<int> suffix(nums.size() + 1);

        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + nums[i];
        }

        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                const int sum = suffix[i] - suffix[j + 1];

                cnt += (sum == k);
            }
        }

        return cnt;
    }
};