class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ranges::sort(nums);
        std::unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) m[nums[i]] = i;
        std::vector<std::vector<int>> result;

        const int n = nums.size();

        for (int i = 0; i < n; ++i) {
            while (i < n && i && nums[i] == nums[i - 1]) ++i;

            for (int j = i + 1; j < n; ++j) {
                const int t = -nums[i] - nums[j];

                if (const auto it = m.find(t); it != m.end() && it->second > j) {
                    result.emplace_back(std::vector<int>{
                        nums[i], nums[j], it->first });
                }

                while (j < n - 1 && nums[j] == nums[j + 1]) ++j;
            }
        }

        return result;
    }
};
