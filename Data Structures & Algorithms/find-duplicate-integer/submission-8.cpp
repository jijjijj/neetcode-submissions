class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ) {
            if (i + 1 == nums[i]) {
                ++i;
                continue;
            }

            // int& a = ;
            // int& b = ;
            std::swap(nums[i], nums[nums[i] - 1]);

            if (nums[nums[i] - 1]== nums[i]) return nums[i];
        }

        return -1;
    }
};
