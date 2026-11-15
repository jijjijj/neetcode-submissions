class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (max < i) break;
            if (i == nums.size() - 1) return true;

            max = std::max(max, i + nums[i]);
        }

        return false;
    }
};
