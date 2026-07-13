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
                const int a = nums[i];
                const int b = nums[j];

                const int sum = -a - b;

                if (const auto it = m.find(sum); it != m.end() && it->second > j) {
                    const int max = std::max(std::max(a, b), sum);
                    const int min = std::min(std::min(a, b), sum);
                    const int mid = max - min;
                    
                    uint64_t key = min;
                    key <<= 18u;
                    key |= mid;
                    key <<= 18u;
                    key |= max;

                    if (!s.count(key)) {
                        result.emplace_back(
                            std::vector<int>{ a, b, sum });
                        s.emplace(key);
                    }
                }
            }
        }

        return result;
    }
};
