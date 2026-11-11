class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        std::vector<int> prefix(nums.size() + 1);

        // prefix[i] = prefix for [0, i)
        for (int i = 0; i < nums.size(); ++i)
            prefix[i + 1] = prefix[i] + !nums[i];

        int mx = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int l = i;
            int r = nums.size() - 1;

            while (l <= r) {
                const int mid = l + (r - l) / 2;

                if (prefix[mid + 1] - prefix[i] <= k) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            // std::cout << r << " " << l << std::endl;
            mx = std::max(mx, r - i + 1);
        }

        return mx;
    }
};