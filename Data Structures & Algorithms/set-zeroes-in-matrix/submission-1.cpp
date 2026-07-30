class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int h = matrix.size();
        const int w = matrix[0].size();

        bool rowZero = false;

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (!matrix[y][x]) {                    
                    matrix[0][x] = 0;

                    if (y)
                        matrix[y][0] = 0;
                    else
                        rowZero = true;
                }
            }
        }

        for (int y = 1; y < h; ++y) {
            for (int x = 1; x < w; ++x) {
                if (!matrix[0][x] || !matrix[y][0]) {   
                    matrix[y][x] = 0;
                }
            }
        }

        if (!matrix[0][0]) {
            std::fill(matrix[0].begin(), matrix[0].end(), 0);
        }

        if (rowZero) {
            for (int y = 0; y < h; ++y) {
                matrix[y][0] = 0;
            }
        }
    }
};
