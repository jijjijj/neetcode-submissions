class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = 1;
        int cur = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] ||
                (nums[i - cur] < nums[i - cur + 1] != nums[i - 1] < nums[i])) {
                cur = (nums[i] == nums[i - 1]) ? 1 : 2;
                continue;
            }
            ++cur;
            mx = std::max(mx, cur);
        }

        return mx;
    }
};