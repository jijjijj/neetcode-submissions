class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        int max = 0;
        int jumps = 0;

        for (int i = 0; i < n - 1; ++i) {
            if (std::min(i + nums[i], n - 1) > max) {
                max = i + nums[i];
                ++jumps;
            }
        }

        return jumps;
    }
};
