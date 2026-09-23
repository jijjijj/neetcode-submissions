class Solution {
public:
    int candy(vector<int>& nums) {
        std::vector<int> candy(nums.size(), 1);

        // 1 2 3 4
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) candy[i] = candy[i - 1] + 1;
        }

        // 4 3 2 1
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) {
                candy[i] = std::max(candy[i + 1] + 1, candy[i]);
            }
        }

        return std::accumulate(candy.begin(), candy.end(), 0);
    }
};