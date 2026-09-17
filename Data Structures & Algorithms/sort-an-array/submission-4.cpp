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
        const int n = nums.size();
        for (int w = 1; w < n; w <<= 1) {
            for (int i = 0; i + w < n; i += w * 2) {
                const int mid = i + w;
                std::vector<int> res(w * 2);
                int ai = i;
                int bi = mid;
                int r = std::min(mid + w, n);

                for (int j = 0; j < res.size(); ++j) {
                    if (ai < mid && bi < r) {
                        res[j] = nums[ai] < nums[bi] ?
                            nums[ai++] : nums[bi++];
                    } else {
                        res[j] = ai < mid ?
                            nums[ai++] : nums[bi++];
                    }
                }

                std::copy(res.begin(), res.end(), nums.begin() + i);
            }
        }

        return nums;
    }
};