class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rx = -1;
        int ry = -1;

        const int h = matrix.size();
        const int w = matrix[0].size();

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (!matrix[y][x]) {
                    if (rx == -1) {
                        rx = x;
                        ry = y;
                    }
                    
                    matrix[ry][x] = 0;
                    matrix[y][rx] = 0;
                }
            }
        }

        for (int y = 0; y < h; ++y) {
            if (!matrix[y][rx] && ry != y)
                std::fill(matrix[y].begin(), matrix[y].end(), 0);
        }

        for (int x = 0; x < w; ++x) {
            if (!matrix[ry][x]) {
                for (int y = 0; y < h; ++y) matrix[y][x] = 0;
            }
        }

        std::fill(matrix[ry].begin(), matrix[ry].end(), 0);
    }
};
