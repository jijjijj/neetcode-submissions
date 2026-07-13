class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::map<int, int> m;

        for (int i = 0; i < k; ++i) ++m[nums[i]];
        
        std::vector<int> result;
        result.reserve(nums.size() - k);

        result.emplace_back((--m.end())->first);
        for (int i = k; i < nums.size(); ++i) {
            if (!--m[nums[i - k]]) m.erase(nums[i - k]);

            ++m[nums[i]];

            result.emplace_back((--m.end())->first);
        }

        return result;
    }
};
