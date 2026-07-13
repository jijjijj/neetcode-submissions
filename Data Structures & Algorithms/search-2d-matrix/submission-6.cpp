#include <ranges>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int h = matrix.size();
        const int w = matrix[0].size();
        int l = 0;
        int r = w * h - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;
            const int row = mid / w;
            const int col = mid % w;
            if (matrix[row][col] < target) l = mid + 1;
            else if (matrix[row][col] > target) r = mid - 1;
            else return true;
        }

        return false;
    }
};
