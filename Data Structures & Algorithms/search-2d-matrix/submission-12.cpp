class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int w = matrix[0].size();
        const int h = matrix.size();

        int c = w - 1;
        int r = 0;

        while (c >= 0 && r < h) {
            if (matrix[r][c] > target) --c;
            else if (matrix[r][c] < target) ++r;
            else return true;
        }

        return false;
    }
};
