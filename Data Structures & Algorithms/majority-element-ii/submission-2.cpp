class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int val1 = 0;
        int cnt2 = 0;
        int val2 = 0;
        const int n = nums.size();

        for (const int v : nums) {
            if (val1 == v) {
                ++cnt1;
            } else if (val2 == v) {
                ++cnt2;
            } else if (!cnt1) {
                cnt1 = 1;
                val1 = v;
            } else if (!cnt2) {
                cnt2 = 1;
                val2 = v;
            } else {
                if (!--cnt1) val1 = 0;
                if (!--cnt2) val2 = 0;
            }
        }

        std::vector<int> res;
        if (cnt1 && std::count(nums.begin(),
            nums.end(), val1) > n / 3) res.emplace_back(val1);
        if (cnt2 && val2!=val1 && std::count(nums.begin(),
            nums.end(), val2) > n / 3) res.emplace_back(val2);
        return res;
    }
};