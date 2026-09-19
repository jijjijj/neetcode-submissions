class Solution {
public:
    // +sorting
    // bit
    // rand
    // boyer moore
    int majorityElement(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (const int val : nums) {
                cnt += (val & (1 << i));
            }

            if (cnt > (nums.size() / 2)) {
                res |= (1 << i);
            }
        }
        return res;
    }
};