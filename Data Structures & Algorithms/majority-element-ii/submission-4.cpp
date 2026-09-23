class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> freq;

        const int k = 2;
        const int n = nums.size();

        for (const int v : nums) {
            ++freq[v];

            if (freq.size() > k) {
                decltype(freq) new_freq;
                for (const auto [val, f] : freq) {
                    if (f > 1) new_freq[val] = freq[val] - 1; 
                }
                freq = std::move(new_freq);
            }
        }

        std::vector<int> res;
        
        for (const auto [v, f] : freq) {
            const int cnt = std::count(nums.begin(), nums.end(), v);

            if (cnt > n / 3) res.emplace_back(v);
        }

        return res;
    }
};