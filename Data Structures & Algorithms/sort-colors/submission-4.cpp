class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;

        for (int two = 0; two < nums.size(); ++two) {
            const int tmp = nums[two];
            nums[two] = 2;

            if (tmp < 2) nums[one++] = 1;
            if (tmp < 1) nums[zero++] = 0;
        }
    }
};