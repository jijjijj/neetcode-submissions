class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = 1;
        int cur1 = 1;
        int cur2 = 1;

        for (int i = 1; i < nums.size(); ++i) {
            cur1 = nums[i] > nums[i - 1] ? cur1 + 1 : 1;
            cur2 = nums[i] < nums[i - 1] ? cur2 + 1 : 1;
            mx = std::max({ mx, cur1, cur2 });
        }

        return mx;
    }
};