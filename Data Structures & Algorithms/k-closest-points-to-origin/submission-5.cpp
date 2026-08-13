class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const auto dist = [&points](int i) {
            const std::vector<int>& p = points[i];
            return p[0] * p[0] + p[1] * p[1];
        };

        int l = 0;
        int r = points.size() - 1;

        while (l <= r) {
            if (l + 1 >= r) {
                if (l + 1 == r && dist(l) > dist(r))
                    std::swap(points[l], points[r]);
                
                break;
            }

            const int mid = l + (r - l) / 2;

            std::swap(points[l + 1], points[mid]);
            if (dist(l) > dist(r)) std::swap(points[l], points[r]);
            if (dist(l + 1) > dist(r)) std::swap(points[l + 1], points[r]);
            if (dist(l) > dist(l + 1)) std::swap(points[l], points[l + 1]);

            int i = l + 1;
            int j = r;

            while (i < j) {
                while (dist(++i) < dist(l + 1));
                while (dist(--j) > dist(l + 1));

                if (i >= j) break;

                std::swap(points[i], points[j]);
            }

            std::swap(points[l + 1], points[j]);

            if (j > k - 1) r = j - 1;
            else if (j < k - 1) l = j + 1;
            else break;
        }

        std::vector<std::vector<int>> res;

        for (int i = 0; i < k; ++i) res.emplace_back(points[i]);

        return res;
    }
};
