class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = 1;
        int cur = 1;

        for (int i = 1; i < nums.size(); ++i) {
            cur = nums[i] > nums[i - 1] ? cur + 1 : 1;
            mx = std::max(mx, cur);
        }

        cur = 1;
        for (int i = 1; i < nums.size(); ++i) {
            cur = nums[i] < nums[i - 1] ? cur + 1 : 1;
            mx = std::max(mx, cur);
        }

        return mx;
    }
};