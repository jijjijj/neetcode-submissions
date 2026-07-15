class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        std::vector<int> res(nums.size());
        
        for (int i = nums.size() - 2; i >= 0; --i) {
            int j = i + 1;

            while (j < nums.size() && nums[j] <= nums[i]) {
                if (res[j] == 0) {
                    j = nums.size();
                    break;
                }

                j += res[j];
            }

            if (j < nums.size()) {
                res[i] = j - i;
            }
        }

        return res;
    }
};
