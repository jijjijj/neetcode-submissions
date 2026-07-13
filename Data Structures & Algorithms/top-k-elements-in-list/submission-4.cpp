class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<std::pair<int, int>> freq;
        std::unordered_map<int, int> f;

        for (int num : nums) ++f[num];

        for (auto [num, fr] : f) {
            freq.emplace_back(std::pair{ fr, num });
        }

        std::ranges::sort(freq);

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.emplace_back(freq[freq.size() - i - 1].second);
        }
        return res;
    }
};
