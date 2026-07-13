class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        const int target = k - 1; 
        int at = std::numeric_limits<int>::max();
        while (at != target) {
            if (l + 1 >= r) {
                if (l + 1 == r && nums[l] < nums[r]) std::swap(nums[l], nums[r]);

                return nums[target];
            }

            at = partition(nums, l, r);

            if (at > target) {
                r = at - 1;
            } else if (at < target) {
                l = at + 1;
            }
        }

        return nums[target];
    }
    
private:
    int partition(vector<int>& nums, int l, int r) const {
        int mid = l + (r - l) / 2;

        std::swap(nums[mid], nums[r - 1]);

        if (nums[l] < nums[r]) std::swap(nums[l], nums[r]);
        if (nums[l] < nums[r - 1]) std::swap(nums[l], nums[r - 1]);
        if (nums[r - 1] < nums[r]) std::swap(nums[r], nums[r - 1]);

        int i = l;
        int j = r - 2;

        while (i <= j) {
            while (nums[i] > nums[r - 1]) ++i;
            while (nums[j] < nums[r - 1]) --j;
            if (i > j) break;

            std::swap(nums[i], nums[j]);
        }

        std::swap(nums[i], nums[r - 1]);

        return i;
    }
};
