class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> res;
        const int w = matrix[0].size();
        const int h = matrix.size();

        std::vector<int> left = { w, h-1 };
        const std::vector<std::pair<int, int>> dirs = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}
        };

        int d = 0;
        int x = -1;
        int y = 0;

        while (left[d % 2]) {
            for (int i = 0; i < left[d % 2]; ++i) {
                x += dirs[d].first;
                y += dirs[d].second;
                res.emplace_back(matrix[y][x]);
            }

            --left[d % 2];
            d = (d + 1) % 4;
        }

        return res;
    }
};
