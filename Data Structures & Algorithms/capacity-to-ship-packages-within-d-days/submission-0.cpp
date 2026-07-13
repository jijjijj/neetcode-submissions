class Solution {
private:
    int how_many_days(vector<int>& weights, int capacity) const {
        int days = 0;
        int curr = 0;

        for (int w : weights) {
            if (w > capacity) return std::numeric_limits<int>::max();

            if (curr + w > capacity) {
                ++days;
                curr = w;
            } else {
                curr += w;
            }
        }

        // std::cout << capacity << " = " << (days + !!curr) << std::endl;

        return days + !!curr;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1;
        int r = weights.size() * 500 / days + 1;

        int d = 0;

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (how_many_days(weights, mid) <= days) {
                d = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return d;
    }
};