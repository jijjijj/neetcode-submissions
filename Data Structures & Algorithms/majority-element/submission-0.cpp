class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int maj = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == maj) ++cnt;
            else {
                if (!--cnt) maj = nums[i];
            }
        }

        return maj;
    }
};