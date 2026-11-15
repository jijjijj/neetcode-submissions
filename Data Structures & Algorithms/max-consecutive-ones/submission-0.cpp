class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0;
        int cur = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) ++cur;
            else cur = 0;

            mx = std::max(cur, mx);
        }

        return mx;
    }
};