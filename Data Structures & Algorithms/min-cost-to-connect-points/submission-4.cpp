class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int cInf = std::numeric_limits<int>::max();
        const int n = points.size();

        int answer = 0;

        std::unordered_set<int> vis;
        std::vector<int> dist(n, cInf);

        int node = 0;
        dist[0] = 0;
        for (int i = 0; i < n - 1; ++i) {
            int next = -1;
            vis.emplace(node);

            for (int j = 0; j < n; ++j) {
                if (vis.contains(j)) continue;

                const int d = std::abs(points[node][0] - points[j][0]) +
                    std::abs(points[node][1] - points[j][1]);
                dist[j] = std::min(dist[j], d);

                if (next == -1 || (dist[j] < dist[next])) {
                    next = j;
                }
            }

            answer += dist[next];
            node = next;
        }

        return answer;
    }
};
