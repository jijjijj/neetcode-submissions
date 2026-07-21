class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();

        int answer = 0;

        std::vector<int> dist(n,
            std::numeric_limits<int>::max());
        std::vector<bool> vis(n);

        dist[0] = 0;

        for (int i = 0; i < n; ++i) {
            int best = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (best == -1 ||
                    dist[j] < dist[best])) best = j;
            }

            vis[best] = true;
            answer += dist[best];

            for (int j = 0; j < n; ++j) {
                const int d = std::abs(points[best][0] - points[j][0]) +
                    std::abs(points[best][1] - points[j][1]);
                if (d < dist[j]) {
                    dist[j] = d;
                }
            }
        }

        return answer;
    }
};
