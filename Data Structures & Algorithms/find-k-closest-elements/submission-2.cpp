class Solution {
public:
    // custom sort
    // search center then expand
    // shrink
    // bin search center then expand
    // binary search the whole subarray
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::sort(arr.begin(), arr.end(),
            [x](const int a, const int b) {
            const int diff = std::abs(a - x) - std::abs(b - x);

            return diff ? (diff < 0) : a < b;
        });

        std::vector<int> res(arr.begin(), arr.begin() + k);
        std::ranges::sort(res);
        return res;
    }
};