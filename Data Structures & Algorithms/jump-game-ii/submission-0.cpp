class Solution {
public:
    int jump(vector<int>& nums) {
        int max = 0;
        int jumps = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (i + nums[i] > max) {
                max = i + nums[i];
                ++jumps;
            }
        }

        return jumps;
    }
};
