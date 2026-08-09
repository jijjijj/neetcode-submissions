class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ) {
            if (i + 1 == nums[i]) {
                ++i;
                continue;
            }

            int& a = nums[i];
            int& b = nums[nums[i] - 1];
            std::swap(a, b);

            if (a == b) return a;
        }

        return -1;
    }
};
