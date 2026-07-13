class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int len = nums.size();

        std::unordered_map<int, int> m;
        std::unordered_set<uint64_t> s;
        for (int i = 0; i < len; ++i) m[nums[i]] = i;

        std::vector<std::vector<int>> result;

        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                const int sum = nums[i] + nums[j];

                if (const auto it = m.find(-sum); it != m.end() && it->second > j) {
                    const int max = 100000 + std::max(std::max(nums[i], nums[j]), nums[it->second]);
                    const int min = 100000 + std::min(std::min(nums[i], nums[j]), nums[it->second]);
                    const int mid = 300000 - max - min;
                    // const int cMask = 0b11'1111'1111'1111'1111'1111'1111'1111'1111;
                    uint64_t key = min;
                    key <<= 18u;
                    key |= mid;
                    key <<= 18u;
                    key |= max;

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
