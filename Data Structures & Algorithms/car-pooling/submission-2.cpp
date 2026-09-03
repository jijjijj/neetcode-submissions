class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::vector<std::pair<int, int>> events; // coord, change
        for (const auto& trip : trips) {
            events.emplace_back(trip[1], -trip[0]);
            events.emplace_back(trip[2], trip[0]);
        }

        std::sort(events.begin(), events.end(),
            [](const auto& a, const auto& b) {
                return a.first < b.first;
            });

        for (const auto& event : events) {
            capacity += event.second;

            if (capacity < 0) return false;
        }

        return true;
    }
};