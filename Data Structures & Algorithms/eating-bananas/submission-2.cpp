class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *std::ranges::max_element(piles);

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (can(piles, mid, h)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

private:
    bool can(std::vector<int>& piles, int k, int h) {
        int hours = 0;

        for (int p : piles) {
            hours += p / k + !!(p % k);
        }

        return hours <= h;
    }
};
