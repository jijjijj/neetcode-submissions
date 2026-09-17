class Solution {
public:
    // +quick sort - +iterative
    // merge sort - iterative?
    // heap sort - iterative?
    // radix sort
    // counting sort
    // shell sort
    // insertion sort
    // selection sort
    // bucket sort
    vector<int> sortArray(vector<int>& nums) {
        merge(nums, 0, nums.size() - 1);

        return nums;
    }

private:
    void merge(std::vector<int>& nums, int l, int r) {
        if (l >= r) return;
        
        const int mid = l + (r - l) / 2;

        merge(nums, l, mid);
        merge(nums, mid + 1, r);

        std::vector<int> res(r - l + 1);
        int ai = l;
        int bi = mid + 1;

        for (int i = 0; i < res.size(); ++i) {
            if (ai <= mid && bi <= r) {
                res[i] = nums[ai] < nums[bi] ? nums[ai++] : nums[bi++];
            } else {
                res[i] = ai <= mid ? nums[ai++] : nums[bi++];
            }
        }

        std::copy(res.begin(), res.end(), nums.begin() + l);
    }
};