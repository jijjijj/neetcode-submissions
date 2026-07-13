class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>, std::greater<>> freq;
        std::unordered_map<int, int> f;

        for (int num : nums) ++f[num];

        for (auto [num, fr] : f) {
            freq.push(std::pair{ fr, num });

            if (freq.size() > k) {
                freq.pop();
            }
        }


        vector<int> res;
        while (!freq.empty()) {
            res.emplace_back(freq.top().second);
            freq.pop();
        }
        return res;
    }
};
