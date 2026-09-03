class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::vector<int> res(nums.size() * 2);

        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < nums.size(); ++i) {
                res[i + j * nums.size()] = nums[i];
            }
        }

        return res;
    }
};