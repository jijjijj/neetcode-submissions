class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();

        std::vector<int> suffix(nums.size() + 1);
        std::unordered_map<int, std::vector<int>>
            mp2; // suffix, count

        mp2[0] = { n };

        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + nums[i];
            mp2[suffix[i]].emplace_back(i);
        }

        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            const auto& mp = mp2[suffix[i] - k];
            // const int c = std::upper_bound(mp.begin(),
            //     mp.end(), i) - mp.begin();
            // cnt += c;
            for (const int v : mp) {
                cnt += (v > i);
            }
        }

        return cnt;
    }
};