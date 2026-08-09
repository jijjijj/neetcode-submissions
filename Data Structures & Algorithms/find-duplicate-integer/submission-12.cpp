class Solution {
public:
    // neg marking
    // cyclic sort
    // fast & slow
    // bs
    // 
    int findDuplicate(vector<int>& nums) {
        int l = 1;
        int r = nums.size() - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            int less = 0;
            int equal = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] < mid) ++less;
                if (nums[i] == mid) ++equal;
            }

            if (equal > 1) return mid;

            if (less < mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return -1;
    }
};
