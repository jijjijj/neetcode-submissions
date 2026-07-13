class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ranges::sort(nums);

        const int len = nums.size();

        std::vector<std::vector<int>> result;

        // for (int x : nums) std::cout << x << " ";

        for (int i = 0; i < len; ++i) {
            while (i && i < len && nums[i] == nums[i - 1]) ++i;

            int left = i + 1;
            int right = len - 1;

            while (left < right) {
                const int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.emplace_back(std::vector<int>{
                        nums[i], nums[left], nums[right] });

                    ++left;
                    --right;
                } else if (sum > 0) --right;
                else ++left;
            }
        }

        return result;
    }
};
