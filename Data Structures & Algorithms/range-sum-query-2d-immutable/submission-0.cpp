class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) : matrix(matrix) {
        for (int y = 0; y < matrix.size(); ++y) {
            for (int x = 0; x < matrix[0].size(); ++x) {
                int prev = 0;
                if (y && x) {
                    prev -= matrix[y - 1][x - 1];
                }
                if (y) {
                    prev += matrix[y - 1][x];
                }
                if (x) {
                    prev += matrix[y][x - 1];
                }
                matrix[y][x] += prev;
            }
        }
    }
    
    int sumRegion(int y1, int x1, int y2, int x2) {
        int prev = matrix[y2][x2];
        if (y1 && x1) {
            prev += matrix[y1 - 1][x1 - 1];
        }
        if (y1) {
            prev -= matrix[y1 - 1][x2];
        }
        if (x1) {
            prev -= matrix[y2][x1 - 1];
        }
        return prev;
    }

private:
    vector<vector<int>>& matrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */