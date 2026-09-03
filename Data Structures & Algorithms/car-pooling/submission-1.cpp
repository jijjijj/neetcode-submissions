class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::sort(trips.begin(), trips.end(),
            [](const auto& a, const auto& b) {
                return a[1] < b[1];
            });

        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>> drop; // end, pass num

        for (const auto& trip : trips) {
            while (!drop.empty() &&
                drop.top().first <= trip[1]) {
                capacity += drop.top().second;
                drop.pop();
            }

            capacity -= trip[0];

            if (capacity < 0) return false;

            drop.push({ trip[2], trip[0] });
        }

        return true;
    }
};