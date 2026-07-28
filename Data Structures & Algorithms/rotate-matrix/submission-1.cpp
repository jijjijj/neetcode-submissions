class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        int l = 0;
        int r = n - 1;

        while (l < r) {
            for (int i = 0; i < r - l; ++i) {
                // left to top
                const int top = matrix[l][l + i];
                matrix[l][l + i] = matrix[r - i][l];
                // bottom to left
                matrix[r - i][l] = matrix[r][r - i];
                // right to bottom
                matrix[r][r - i] = matrix[l + i][r];
                // top to right
                matrix[l + i][r] = top;
            }

            ++l;
            --r;
        }
    }
};
