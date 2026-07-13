class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, std::vector<int>> freq;
        std::unordered_map<int, int> f;

        for (int num : nums) ++f[num];

        for (auto [num, fr] : f) {
            freq[fr].emplace_back(num);
        }

        vector<int> res;
        int cur = 10000;
        while (k > 0) {
            if (freq.contains(cur)) {
                res.insert(res.end(), freq[cur].begin(), freq[cur].end());
                k -= freq[cur].size();
            }
            --cur;
        }
        return res;
    }
};
