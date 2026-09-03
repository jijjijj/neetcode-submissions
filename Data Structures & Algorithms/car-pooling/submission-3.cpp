class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int min = std::numeric_limits<int>::max();
        int max = std::numeric_limits<int>::min();

        for (const auto& trip : trips) {
            min = std::min(min, trip[1]);
            max = std::max(max, trip[2]);
        }

        std::vector<int> road(max - min + 1); // coord, change
        for (const auto& trip : trips) {
            road[trip[1] - min] += trip[0];
            road[trip[2] - min] -= trip[0];
        }

        int cur = 0;

        for (int change : road) {
            cur += change;

            if (cur > capacity) return false;
        }

        return true;
    }
};