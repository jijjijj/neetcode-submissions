class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *std::max_element(weights.begin(),
            weights.end());
        int r = (l * weights.size()) / days + 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (valid(weights, mid, days)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

private:
    bool valid(const std::vector<int>& weights,
        int cap, int days) {
        int cur = 0;
        int used = 0;

        for (const int w : weights) {
            if (cur + w > cap) {
                cur = 0;
                ++used;
            }
            cur += w;
        }

        return used + 1 <= days;
    }
};