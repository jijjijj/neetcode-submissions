class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0;
        int r = h.size() - 1;

        int vol = 0;

        int maxl = l; // index
        int maxr = r; // index

        while (l <= r) {
            if (h[l] >= h[r]) {
                maxr = h[r] > h[maxr] ? r : maxr;
                vol += std::max(h[maxr] - h[r], 0);
                --r;
            } else {
                maxl = h[l] > h[maxl] ? l : maxl;
                vol += std::max(h[maxl] - h[l], 0);
                ++l;
            }
        }

        return vol;
    }
};
