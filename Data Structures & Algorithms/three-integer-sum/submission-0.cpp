class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int len = nums.size();

        std::unordered_map<int, int> m;
        std::unordered_set<int> s;
        for (int i = 0; i < len; ++i) m[nums[i]] = i;

        std::vector<std::vector<int>> result;

        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                const int sum = nums[i] + nums[j];

                if (const auto it = m.find(-sum); it != m.end() && it->second > j) {
                    const int key = nums[i] ^ nums[j] ^ nums[it->second];

                    if (!s.count(key)) {
                        result.emplace_back(std::vector<int>{
                            nums[i], nums[j], nums[it->second] });
                        s.emplace(key);
                    }
                }
            }
        }

        return result;
    }
};
