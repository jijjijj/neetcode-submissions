class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        const int cInf = std::numeric_limits<int>::max();

        std::vector<std::tuple<int, int, int, int>> events; // coord, type, length

        for (int i = 0; i < intervals.size(); ++i) {
            events.push_back({ intervals[i][0], 0,
                intervals[i][1] - intervals[i][0] + 1, i });
            events.push_back({ intervals[i][1], 2,
                intervals[i][1] - intervals[i][0] + 1, i });
        }

        for (int i = 0; i < queries.size(); ++i) {
            events.push_back({ queries[i], 1, cInf, i });
        }

        std::sort(events.begin(), events.end());

        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>> pq; // length, i
        std::vector<bool> deleted(intervals.size());

        std::vector<int> res(queries.size());

        for (int i = 0; i < events.size(); ++i) {
            const auto [_, type, len, ind] = events[i];

            if (type == 0) {
                pq.push(std::pair{ len, ind });
            } else if (type == 1) {
                while (!pq.empty() && deleted[pq.top().second]) {
                    pq.pop();
                }

                res[ind] = pq.empty() ? -1 : pq.top().first;
            } else if (type == 2) {
                deleted[ind] = true;
            }
        }

        return res;
    }
};
