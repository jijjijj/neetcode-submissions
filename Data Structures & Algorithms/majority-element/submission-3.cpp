class Solution {
public:
    // +sorting
    // bit
    // rand
    // boyer moore
    int majorityElement(vector<int>& nums) {
        int maj = 0;
        int cnt = 0;

        for (const int val : nums) {
            if (!cnt) maj = val;

            cnt += (maj == val ? 1 : -1);
        }

        return maj;
    }
};