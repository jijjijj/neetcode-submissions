class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = nums.size();

        std::vector<int> prefix(n + 1);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];

        int l = 0;
        int min = n + 1;
        int cur = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int l = i;
            int r = n - 1;

            while (l <= r) {
                const int mid = l + (r - l) / 2;

                if (prefix[mid + 1] - prefix[i] >= target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (l < n) {
                min = std::min(min, (l - i + 1));
            }
        }

        return min % (n + 1);
    }
};