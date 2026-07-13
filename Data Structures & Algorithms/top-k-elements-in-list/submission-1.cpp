class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::array<int, 2001> freq = {};

        for (const auto x : nums) {
            ++freq[x + 1000];
            // std::cout << x << " " << freq[x + 1000] << std::endl;
        }

        std::vector<int> result;
        result.reserve(k);

        for (int i = 0; i < k; ++i) {
            // std::cout << "it" << std::endl;
            int max = 0;
            for (int j = 0; j <= 2000; ++j) {
                if (freq[max] < freq[j]) {
            // std::cout << "set = " << j << " bec " << freq[j] << std::endl;

                    max = j;
                }
            }
            // std::cout << "add " << (max - 1000) << std::endl;

            result.emplace_back(max - 1000);
            freq[max] = 0;
        }

        return result;
    }
};
