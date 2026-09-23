class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::vector<int> res;
        
        std::ranges::sort(nums);

        int cnt = 0;
        int last = std::numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); ++i) {
            if (i && nums[i] == nums[i - 1]) ++cnt;
            else cnt = 1;

            if (cnt > nums.size() / 3 && last != nums[i]) {
                res.emplace_back(nums[i]);
                last = nums[i];
            }
        }

        return res;
    }
};