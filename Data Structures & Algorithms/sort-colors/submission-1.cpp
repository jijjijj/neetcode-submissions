class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        // 0 1 1 2
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0 && i > l)
                std::swap(nums[l++], nums[i--]);
            else if (nums[i] == 2 && i < r)
                std::swap(nums[r--], nums[i--]);
        }
    }
};