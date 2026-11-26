class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        const int cInf = std::numeric_limits<int>::max();

        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>> pq; // length, coord

        std::vector<int> qs(queries.size());
        std::iota(qs.begin(), qs.end(), 0);

        std::sort(qs.begin(), qs.end(), [&queries](const auto& a, const auto& b) {
            return queries[a] < queries[b];
        });

        std::vector<int> res(queries.size(), -1);

        int i = 0;

        for (const int q : qs) {
            while (i < intervals.size() &&
                intervals[i][0] <= queries[q]) {
                pq.push(std::pair{
                    intervals[i][1] - intervals[i][0] + 1,
                    intervals[i][1] });
                ++i;
            }

            while (!pq.empty() && pq.top().second < queries[q]) pq.pop();

            if (!pq.empty()) {
                res[q] = pq.top().first;
            }
        }

        return res;
    }
};
