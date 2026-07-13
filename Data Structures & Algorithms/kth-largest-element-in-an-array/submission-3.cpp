class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        const int target = nums.size() - k; 
        int at = std::numeric_limits<int>::max();
        while (at != target) {
            at = partition(nums, l, r);

            if (at > target) {
                r = at - 1;
            } else if (at < target) {
                l = at + 1;
            }
        }

        // for (const auto& v : nums) std::cout << v << " ";

        return nums[target];
    }
    
private:
    int partition(vector<int>& nums, int l, int r) const {
        int pivot_index = r;
        int pivot = nums[pivot_index];
        int at = l;

        for (int i = l; i < r; ++i) {
            if (nums[i] < pivot) {
                std::swap(nums[i], nums[at++]);
            }
        }

        std::swap(nums[at], nums[pivot_index]);

        return at;
    }
};
