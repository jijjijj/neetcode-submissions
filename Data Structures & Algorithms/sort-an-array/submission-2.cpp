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
        return merge(nums, 0, nums.size() - 1);
    }

private:
    std::vector<int> merge(const std::vector<int>& nums,
        int l, int r) {
        if (l > r) return {};
        if (l == r) return { nums[l] };
        
        const int mid = l + (r - l) / 2;

        const std::vector<int> a = merge(nums, l, mid);
        const std::vector<int> b = merge(nums, mid + 1, r);

        std::vector<int> res(a.size() + b.size());
        int ai = 0;
        int bi = 0;

        for (int i = 0; i < res.size(); ++i) {
            if (ai < a.size() && bi < b.size()) {
                res[i] = a[ai] < b[bi] ? a[ai++] : b[bi++];
            } else {
                res[i] = ai < a.size() ? a[ai++] : b[bi++];
            }
        }

        return res;
    }
};