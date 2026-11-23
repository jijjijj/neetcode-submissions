class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool valid = true;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                valid = false;
                break;
            }
        }

        if (valid) return true;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) return false;
        }

        return true;
    }
};