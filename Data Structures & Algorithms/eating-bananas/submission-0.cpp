class Solution {
public:
    int find_h(vector<int>& piles, int k) const {
        int h = 0;

        for (int p : piles) {
            const int hl = p / k;
            h += hl + ((p - hl * k) > 0 ? 1 : 0);
        }

        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxk = 0;

        for (int p : piles) maxk = std::max(maxk, p);

        int l = 1;
        int r = maxk;

        int mink = maxk;
        while (l <= r) {
            const int mid = l + (r - l) / 2;
            const int fh = find_h(piles, mid);

            if (fh > h) l = mid + 1;
            else {
                r = mid - 1;
                mink = std::min(mink, mid);
            } 
        }

        return mink;
    }
};
