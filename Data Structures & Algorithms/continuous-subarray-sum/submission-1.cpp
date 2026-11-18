class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        std::unordered_set<int> mp;

        for (const int v : nums) {
            const int rem = v % k;

            std::unordered_set<int> mp2;
            
            for (const int p : mp) {
                mp2.emplace((p + v) % k);
            }

            mp = std::move(mp2);

            if (mp.contains(0)) return true;

            mp.emplace(rem);
        }

        return false;
    }
};