class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        int l = 0, r = 0;
        int jumps = 0;

        while (r < nums.size() - 1) {
            int far = 0;
            for (int i = l; i <= r; ++i) {
                far = std::max(i + nums[i], far);
            }

            ++jumps;
            l = r;
            r = far;
        }

        return jumps;
    }
};
