class Solution {
public:
    // sorting
    // bit
    // rand
    // boyer moore
    int majorityElement(vector<int>& nums) {
        std::ranges::sort(nums);

        return nums[nums.size() / 2];
    }
};