class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int to = 0;

        while (i < nums.size()) {
            int cnt = 1;
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                ++cnt;
                ++i;
            }

            for (int j = 0; j < std::min(2, cnt); ++j) {
                nums[to++] = nums[i];
            }
            ++i;
        }

        return to;
    }
};