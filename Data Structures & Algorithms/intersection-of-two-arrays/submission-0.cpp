class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> mp(1001);

        for (const int v : nums1) mp[v] = 1;

        std::vector<int> res;

        for (const int v : nums2) {
            if (mp[v]) {
                --mp[v];
                res.emplace_back(v);
            } 
        }

        return res;
    }
};