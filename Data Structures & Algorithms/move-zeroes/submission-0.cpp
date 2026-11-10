class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int from = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) continue;

            from = i + 1;
            while (from < nums.size() && !nums[from]) {
                ++from;
            }

            if (from < nums.size()) std::swap(nums[i], nums[from]);
        }
    }
};