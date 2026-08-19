class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *std::min_element(nums.begin(), nums.end());
        int r = std::accumulate(nums.begin(), nums.end(), 0);

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (check(nums, k, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

private:
    bool check(const std::vector<int>& nums, int k, int sum) {
        int pcs = 0;
        int cur = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > sum) return false;

            if (cur + nums[i] > sum) {
                cur = 0;
                ++pcs;
            }

            cur += nums[i];
        }

        return pcs < k;
    }
};