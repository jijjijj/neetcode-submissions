class Solution {
public:
    // +custom sort
    // +search center then expand
    // +shrink
    // bin search center then expand
    // binary search the whole subarray
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (arr[mid] < x) {
                l = mid + 1;
            } else if (arr[mid] >= x) {
                r = mid - 1;
            }
        }

        int t = l;

        l = t - 1;
        r = t;

        while ((r - l - 1) < k) {
            if (l >= 0 && r < arr.size()) {
                if (x - arr[l] > arr[r] - x) {
                    ++r;
                } else {
                    --l;
                }
            } else if (l >= 0) {
                --l;
            } else if (r < arr.size()) {
                ++r;
            }
        }

        return std::vector(arr.begin() + l + 1, arr.begin() + l + k + 1);
    }
};