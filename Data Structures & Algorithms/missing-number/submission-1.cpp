class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();

        int x = n;

        for (int i = 0; i < n; ++i) {
            x += i - nums[i];
        }

        return x;
    }
};
