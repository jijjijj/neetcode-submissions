class Solution {
public:
    // +custom sort
    // search center then expand
    // shrink
    // bin search center then expand
    // binary search the whole subarray
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = 0;

        for (int i = 0; i < arr.size(); ++i) {
            if (std::abs(arr[i] - x) < std::abs(arr[idx] - x)) {
                idx = i;
            }
        }

        int l = idx - 1;
        int r = idx + 1;

        std::vector<int> res{ arr[idx] };

        while (res.size() < k) {
            int i = 0;
            if (l >= 0 && r < arr.size()) {
                if ((x - arr[l]) > (arr[r] - x))
                    i = r++;
                else
                    i = l--;
            } else if (l >= 0) {
                i = l--;
            } else if (r < arr.size()) {
                i = r++;
            }
            
            res.emplace_back(arr[i]);
        }

        std::ranges::sort(res);
        return res;
    }
};