class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int w = matrix[0].size();
        const int h = matrix.size();

        int l = 0;
        int r = h - 1;

        int row = -1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            const int val = matrix[mid][0];
            if (val >= target) {
                r = mid - 1;
            } else if (val < target) {
                l = mid + 1;
            }
        }

        if (l < 1 || l >= h) return false;

        row = l - 1;

        l = 0;
        r = w - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;
            const int val = matrix[row][mid];

            if (val > target) {
                r = mid - 1;
            } else if (val < target) {
                l = mid + 1;
            } else {
                return true;
            }
        } 

        return false;
    }
};
