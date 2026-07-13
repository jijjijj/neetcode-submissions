class Solution {
public:
    vector<int> minInterval(
        vector<vector<int>>& intervals,
        vector<int>& queries) {
        std::ranges::sort(intervals);

        int max_end = std::ranges::max(intervals, {},
            [](const std::vector<int>& i) { return i[1]; })[1];
        max_end = std::max(max_end, std::ranges::max(queries));

        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>> pq; // length, end

        std::vector<int> data(max_end);
        for (int i = 0, j = 0; i < max_end; ++i) {
            while (j < intervals.size() && intervals[j][0] - 1 == i) {
                pq.push(std::pair{ intervals[j][1] - intervals[j][0] + 1, intervals[j][1] - 1 });
                ++j;
            }

            if (pq.empty()) {
                data[i] = -1;
            } else {
                data[i] = pq.top().first;
            }

            while (!pq.empty() && pq.top().second <= i) {
                pq.pop();
            }
        }

        std::vector<int> result;
        result.reserve(queries.size());

        for (int i : queries) {
            result.emplace_back(data[i - 1]);
        }

        return result;
    }
};
