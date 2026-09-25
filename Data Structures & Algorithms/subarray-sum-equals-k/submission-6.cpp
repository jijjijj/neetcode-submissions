class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();

        std::vector<int> suffix(nums.size() + 1);
        std::unordered_map<int, int>
            mp2; // suffix, count

        mp2[0] = 1;

        int cnt = 0;

        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + nums[i];
            // if (!mp2.contains(suffix[i])) mp2[suffix[i]].resize(n + 1);
            cnt += mp2[suffix[i] - k];

            ++mp2[suffix[i]]; // [i] = mp2[suffix[i]][i + 1] + 1
        }


        std::unordered_set<int> calc;

        // for (int i = 0; i < n; ++i) {
        //     // if (!calc.contains(suffix[i] - k)) {
        //         // mp2[suffix[i] - k] = 0;
        //         // if (suffix[i] - k == suffix[i]) --cnt;
        //         // calc.emplace(suffix[i] - k);
        //     // }
        // }

        return cnt;
    }
};