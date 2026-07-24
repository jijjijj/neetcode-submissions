class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();

        int x = 0;

        for (int v : nums) x += v;

        return (n * (n + 1)) / 2 - x;
    }
};
