class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (max >= i) {
                max = std::max(max, i + nums[i]);

                if (i == nums.size() - 1) return true;
            }
        }

        return false;
    }
};
