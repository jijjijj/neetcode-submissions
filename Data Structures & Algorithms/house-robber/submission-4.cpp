class Solution {
public:
    int rob(vector<int>& nums) {
        int one = 0;
        int two = 0;

        for (int i = 0; i < nums.size(); ++i) {
            const int temp = std::max(nums[i] + one, two);
            one = two;
            two = temp;
        }

        return two;
    }
};
