class Solution {
public:
    // neg marking
    // cyclic sort
    // fast & slow
    // bs
    // 
    int findDuplicate(vector<int>& nums) {
        int result = 0;

        for (int i = 0; i < 32; ++i) {
            int need = 0;
            for (int j = 1; j < nums.size(); ++j) {
                need += (j >> i) & 1; 
            }

            int have = 0;
            for (int n : nums) {
                have += (n >> i) & 1;
            }

            if (have > need) result |= (1 << i);
        }

        return result;
    }
};
