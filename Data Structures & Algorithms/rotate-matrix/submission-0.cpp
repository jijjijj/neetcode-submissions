class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        for (int y = 0; y < n; ++y) {
            for (int x = y; x < n; ++x) {
                std::swap(matrix[y][x], matrix[x][y]);
            }
        }

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n / 2; ++x) {
                std::swap(matrix[y][x], matrix[y][n - x - 1]);
            }
        }
    }
};
