class Solution {
public:
    // dp
    // sliding window
    // +iteration
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0;
        int r = 1;
        int expect = 0;
        int max = 1;

        while (r < arr.size()) {
            if (arr[r - 1] < arr[r] && expect != 1) {
                max = std::max(max, r - l + 1);
                ++r;
                expect = 1;
            } else if (arr[r - 1] > arr[r] && expect != -1) {
                max = std::max(max, r - l + 1);
                ++r;
                expect = -1;
            } else {
                l = r;
                r = (arr[r - 1] == arr[r] ? r + 1 : r);
                expect = 0;
            }
        }

        return max;
    }
};