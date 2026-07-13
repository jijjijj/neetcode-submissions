class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::vector<std::vector<int>> result;

        using element_type = std::pair<double, int>; // dist, index
        std::priority_queue<element_type, std::vector<element_type>,
            std::greater<element_type>> q;

        for (int i = 0; i < points.size(); ++i) {
            q.push(std::pair{
                points[i][0] * points[i][0] +
                points[i][1] * points[i][1], i });
        }

        while (k--) {
            auto [_, index] = q.top();
            q.pop();

            result.emplace_back(std::vector<int>{
                points[index][0], points[index][1] });
        }

        return result;
    }
};
