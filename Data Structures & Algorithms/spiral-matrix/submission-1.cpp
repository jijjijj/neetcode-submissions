class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> res;
        rot(matrix, res, 0, -1, 0, 1, matrix.size(), matrix[0].size());
        return res;
    }

private:
    void rot(const std::vector<std::vector<int>>& matrix,
        std::vector<int>& res, int row, int col,
        int dr, int dc, int rowl, int coll) {
        if (!rowl || !coll) return;

        for (int i = 0; i < coll; ++i) {
            row += dr;
            col += dc;
            res.emplace_back(matrix[row][col]);
        }

        rot(matrix, res, row, col, dc, -dr, coll, rowl-1);
    }
};
