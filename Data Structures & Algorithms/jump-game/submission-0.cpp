class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0; // index

        for (int i = 0; i < nums.size(); ++i) {
            max = std::max(max, i + nums[i]);

            if (max == i && i < nums.size() - 1) return false;
        }

        return true;
    }
};
