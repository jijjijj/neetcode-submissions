class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int w = matrix[0].size();
        const int h = matrix.size();

        int l = 0;
        int r = w * h - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            const int val = matrix[mid / w][mid % w];
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
