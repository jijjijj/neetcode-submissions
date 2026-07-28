class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> res;
        const int w = matrix[0].size();
        const int h = matrix.size();

        int l = 0;
        int r = w;
        int b = h;
        int t = 0;
        while (l < r && t < b) {
            for (int i = l; i < r; ++i) {
                res.emplace_back(matrix[t][i]);
            }
            ++t;
            for (int i = t; i < b; ++i) {
                res.emplace_back(matrix[i][r - 1]);
            }
            --r;
            if (!(l < r && t < b)) break;
            for (int i = r - 1; i >= l; --i) {
                res.emplace_back(matrix[b - 1][i]);
            }
            --b;
            for (int i = b - 1; i >= t; --i) {
                res.emplace_back(matrix[i][l]);
            }
            ++l;
        }

        return res;
    }
};
