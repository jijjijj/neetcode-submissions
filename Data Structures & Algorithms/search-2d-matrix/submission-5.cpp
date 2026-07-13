#include <ranges>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const auto it = std::ranges::lower_bound(
            matrix, target, std::ranges::less{},
            [](const vector<int>& v) { return v[0]; });

        if (it != matrix.end() && (*it)[0] == target) return true;

        int row = it - matrix.begin() - 1;
        
        if (row < 0) return false;

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
