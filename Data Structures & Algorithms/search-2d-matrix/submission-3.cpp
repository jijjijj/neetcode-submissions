#include <ranges>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const auto it = std::ranges::upper_bound(
            matrix, target, std::ranges::less{},
            [](const vector<int>& v) { return v[0]; });

        if (it == matrix.end()) return false;

        int row = it - matrix.begin();
        if (matrix[row][0] == target) return true;
        else if (matrix[row][0] > target && !row) return false;
        --row;
        int l = 0;
        int r = matrix[0].size() - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;
            if (matrix[row][mid] < target) l = mid + 1;
            else if (matrix[row][mid] > target) r = mid - 1;
            else return true;
        }

        return false;
    }
};
