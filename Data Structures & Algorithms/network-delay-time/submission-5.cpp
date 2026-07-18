class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::vector<int> dist(n + 1, 100001);
        dist[k] = 0;

        for (int i = 0; i < n; ++i) {
            bool change = false;

            for (const auto& t : times) {
                if (dist[t[1]] > dist[t[0]] + t[2]) {
                    dist[t[1]] = dist[t[0]] + t[2];
                    change = true;
                }
            }

            if (!change) break;
        }

        const int max = *std::max_element(dist.begin() + 1, dist.end());

        return max == 100001 ? -1 : max;
    }
};
