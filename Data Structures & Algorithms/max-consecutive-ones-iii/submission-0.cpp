class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int cur = 0;
        int mx = 0;

        for (int i = 0; i < nums.size(); ++i) {
            cur += !nums[i];

            while (cur > k) {
                cur -= !nums[l++];
            }
            
            mx = std::max(mx, i - l + 1);
        }

        return mx;
    }
};