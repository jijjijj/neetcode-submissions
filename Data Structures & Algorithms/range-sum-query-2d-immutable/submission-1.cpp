class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) :
        prefix(matrix.size() + 1,
            std::vector<int>(matrix[0].size() + 1)) {
        for (int y = 0; y < matrix.size(); ++y) {
            int p = 0;
            for (int x = 0; x < matrix[0].size(); ++x) {
                p += matrix[y][x];
                prefix[y + 1][x + 1] = p + prefix[y][x + 1];
            }
        }
    }
    
    int sumRegion(int y1, int x1, int y2, int x2) {
        return prefix[y2 + 1][x2 + 1] -
            prefix[y2 + 1][x1] -
            prefix[y1][x2 + 1] +
            prefix[y1][x1];
    }

private:
    vector<vector<int>> prefix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */