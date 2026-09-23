class Solution {
public:
    int candy(vector<int>& nums) {
        const int n = nums.size();

        int sum = n;
        int i = 1;

        while (i < n) {
            if (nums[i] == nums[i - 1]) {
                ++i;
                continue;
            }

            int inc = 0;
            while (i < n && nums[i] > nums[i - 1]) {
                ++inc;
                sum += inc;
                ++i;
            }

            int dec = 0;
            while (i < n && nums[i] < nums[i - 1]) {
                ++dec;
                sum += dec;
                ++i;
            }

            sum -= std::min(dec, inc);
        }

        return sum;
    }
};