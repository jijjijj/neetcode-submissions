class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using value_t = std::tuple<int, int, int>; // dist sq., x, y
        std::priority_queue<value_t> q;

        for (const auto& p : points) {
            const int dist = p[0] * p[0] + p[1] * p[1];

            q.push({ dist, p[0], p[1] });

            if (q.size() > k) q.pop();
        }

        std::vector<std::vector<int>> res;

        while (!q.empty()) {
            const auto [_, x, y] = q.top();
            q.pop();

            res.emplace_back(std::vector<int>{ x, y });
        }

        return res;
    }
};
