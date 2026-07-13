class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;

        {
            int l = 0;
            int r = matrix.size() - 1;

            while (l <= r) {
                const int mid = l + (r - l) / 2;
                if (matrix[mid][0] <= target) l = mid + 1;
                else if (matrix[mid][0] > target) r = mid - 1;
            }

            if (r < 0 || r >= matrix.size()) return false;

            row = r;
        }

        if (matrix[row][0] == target) return true;

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
