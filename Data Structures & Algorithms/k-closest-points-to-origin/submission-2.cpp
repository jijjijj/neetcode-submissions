class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::vector<std::vector<int>> result;
        
        int l = 0;
        int r = points.size() - 1;
        while (l <= r) {
            const int pivot = partition(points, l, r);

            if (pivot > k) {
                r = pivot - 1;
            } else if (pivot < k) {
                l = pivot + 1;
            } else break;
        }

        result.assign(points.begin(), points.begin() + k);
        return result;
    }

private:
    int partition(std::vector<std::vector<int>>& points, int l, int r) const {
        const auto dist = [](const std::vector<int>& point) {
            return point[0] * point[0] + point[1] * point[1];
        };

        const int pivot_index = r;
        const int val = dist(points[pivot_index]);

        int at = l;
        for (int i = l; i < r; ++i) {
            if (dist(points[i]) < val) {
                std::swap(points[i], points[at]);
                ++at;
            }
        }

        std::swap(points[at], points[pivot_index]);

        return at;
    }
};
