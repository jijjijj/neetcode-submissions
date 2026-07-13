class Solution {
public:
    vector<int> minInterval(
        vector<vector<int>>& intervals,
        vector<int>& queries) {
        std::ranges::sort(intervals);

        std::vector<std::pair<int, int>> q; // query, initial index
        for (int i = 0; i < queries.size(); ++i)
            q.emplace_back(std::pair{ queries[i], i });
        std::ranges::sort(q);

        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>> pq; // length, end
        
        std::vector<int> result;
        result.resize(queries.size());

        int j = 0;
        for (auto [qr, i] : q) {
            while (j < intervals.size() && intervals[j][0] <= qr) {
                pq.push(std::pair{ intervals[j][1] - intervals[j][0] + 1,
                    intervals[j][1] });
                ++j;
            }

            while (!pq.empty() && pq.top().second < qr) pq.pop();

            result[i] = pq.empty() ? -1 : pq.top().first;
        }

        return result;
    }
};
