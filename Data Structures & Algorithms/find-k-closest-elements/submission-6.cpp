class Solution {
public:
    // +custom sort
    // +search center then expand
    // +shrink
    // +bin search center then expand
    // binary search the whole subarray
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - k - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (std::abs(arr[mid] - x) <= std::abs(arr[mid + k] - x)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return std::vector(arr.begin() + l, arr.begin() + l + k);
    }
};