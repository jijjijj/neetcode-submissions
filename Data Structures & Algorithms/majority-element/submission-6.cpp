class Solution {
public:
    // +sorting
    // +bit
    // rand
    // +boyer moore
    int majorityElement(vector<int>& nums) {
        while (true) {
            const int val = nums[rand() % nums.size()];
            int cnt = 0;

            for (const int v : nums)
                cnt += (val == v);

            if (cnt > (nums.size() / 2)) return val;
        }

        return -1;
    }
};