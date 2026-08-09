class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (i == nums[i]) continue;
            
            std::swap(nums[i], nums[nums[i]]);

            if (nums[i] == nums[nums[i]]) return nums[i];
        }

        return -1;
    }
};
