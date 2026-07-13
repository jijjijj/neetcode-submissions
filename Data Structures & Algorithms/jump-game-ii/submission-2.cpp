class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        int max = 0;
        int next = 0;
        int jumps = 0;

        for (int i = 0; i < n - 1; ++i) {
            if (i + nums[i] > next) {
                next = i + nums[i];
            }
            
            if (max == i) {
                max = next;
                ++jumps;
            }
        }

        return jumps;
    }
};
