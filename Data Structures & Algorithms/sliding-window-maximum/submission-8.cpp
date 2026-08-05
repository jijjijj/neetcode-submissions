class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::map<int, int, std::greater<>> freq;

        std::vector<int> res;
        res.reserve(nums.size() - k);

        for (int i = 0; i < k - 1; ++i) ++freq[nums[i]];
        for (int i = k - 1; i < nums.size(); ++i) {
            ++freq[nums[i]];
            if (i >= k) {
                if (!--freq[nums[i - k]]) freq.erase(nums[i - k]);
            }
            res.emplace_back(freq.begin()->first);
        }

        return res;
    }
};
