class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            if (l + 1 >= r) {
                if (l + 1 == r && nums[l] < nums[r])
                    std::swap(nums[l], nums[r]);

                return nums[k - 1];
            }

            const int mid = l + (r - l) / 2;

            std::swap(nums[l + 1], nums[mid]);

            if (nums[l] < nums[r]) std::swap(nums[l], nums[r]);
            if (nums[l + 1] < nums[r]) std::swap(nums[l + 1], nums[r]);
            if (nums[l] < nums[l + 1]) std::swap(nums[l], nums[l + 1]);

            int i = l + 1;
            int j = r;

            while (l <= r) {
                while (nums[++i] > nums[l + 1]);
                while (nums[--j] < nums[l + 1]);

                if (i >= j) break;

                std::swap(nums[i], nums[j]);
            }

            std::swap(nums[l + 1], nums[j]);

            if (j <= k - 1) l = j + 1;
            if (j >= k - 1) r = j - 1;
        }

        return nums[k - 1];
    }
};
