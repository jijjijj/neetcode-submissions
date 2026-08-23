class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>> take; // coord, pass num
        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>> drop; // coord, pass num

        for (const auto& trip : trips) {
            take.push({ trip[1], trip[0] });
            drop.push({ trip[2], trip[0] });
        }

        while (!take.empty()) {
            while (!drop.empty() &&
                drop.top().first <= take.top().first) {
                capacity += drop.top().second;
                drop.pop();
            }

            capacity -= take.top().second;
            take.pop();

            if (capacity < 0) return false;
        }

        return true;
    }
};