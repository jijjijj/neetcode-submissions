class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int cur = 0;
        int expect = 0;
        int max = 0;

        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i - 1] - arr[i] < 0 && expect < 0) {
                ++cur;
                expect *= -1;
            } else if (arr[i - 1] - arr[i] > 0 && expect > 0) {
                ++cur;
                expect *= -1;
            } else {
                cur = 0;
            }

            if (arr[i] > arr[i - 1] && cur == 0) {
                expect = 1;
                cur = 1;
            } else if (arr[i] < arr[i - 1] && cur == 0) {
                expect = -1;
                cur = 1;
            }

            max = std::max(max, cur);
        }

        return max + 1;
    }
};