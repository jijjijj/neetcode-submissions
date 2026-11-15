class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int jumps = 0;

        while (r < nums.size() - 1) {
            int mx = r;
            for (int j = l; j <= r; ++j) {
                mx = std::max(j + nums[j], mx);
            }
            ++jumps;
            l = r + 1;
            r = mx;
        }

        return jumps;
    }
};
