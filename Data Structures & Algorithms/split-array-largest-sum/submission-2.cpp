class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        std::vector<int> prefix(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i)
            prefix[i + 1] = prefix[i] + nums[i];
        
        int l = *std::max_element(nums.begin(), nums.end());
        int r = std::accumulate(nums.begin(), nums.end(), 0);

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (check(nums, k, mid, prefix)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

private:
    bool check(const std::vector<int>& nums, int k, int sum,
        const std::vector<int>& prefix) {
        int pcs = 0;
        int i = -1;

        while (i < (int)nums.size() - 1) {
            int l = i + 1;
            int r = nums.size() - 1;

            while (l <= r) {
                const int mid = l + (r - l) / 2;

                if (prefix[mid + 1] - prefix[i + 1] <= sum) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            i = r;

            if (++pcs > k) return false;
        }

        return true;
    }
};