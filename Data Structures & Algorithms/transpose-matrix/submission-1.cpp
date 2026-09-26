class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        const int height = matrix.size();
        const int width = matrix[0].size();

        if (height == width) {
            for (int y = 0; y < height; ++y) {
                for (int x = y; x < width; ++x) {
                    std::swap(matrix[y][x], matrix[x][y]);
                }
            }

            return matrix;
        }

        std::vector<std::vector<int>> res(width,
            std::vector<int>(height));

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                res[x][y] = matrix[y][x];
            }
        }

        return res;
    }
};