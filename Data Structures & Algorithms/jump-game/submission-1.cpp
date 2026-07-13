class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0; // index

        for (int i = 0; i < nums.size(); ++i) {
            if (i > max) return false;

            max = std::max(max, i + nums[i]);
        }

        return true;
    }
};
