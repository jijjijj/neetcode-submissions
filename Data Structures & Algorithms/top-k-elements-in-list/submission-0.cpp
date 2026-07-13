class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::array<int, 2001> freq = {};

        for (const auto x : nums) {
            ++freq[x + 1000];
        }

        std::vector<int> result;
        result.reserve(k);

        for (int i = 0; i < k; ++i) {
            int max = 0;
            for (int j = 0; j <= 2001; ++j) {
                if (freq[max] < freq[j]) {
                    max = j;
                }
            }

            result.emplace_back(max - 1000);
            freq[max] = 0;
        }

        return result;
    }
};
