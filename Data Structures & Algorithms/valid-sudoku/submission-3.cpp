class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<int> rows(9);
        std::vector<int> cols(9);
        std::vector<int> sqrs(9);

        const int h = board.size();
        const int w = board[0].size();

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (board[y][x] == '.') continue;

                const int row = y;
                const int col = x;
                const int sq = y / 3 * 3 + x / 3;
                const int v = board[y][x] - '1';

                if ((rows[row] >> v) & 1) return false;
                if ((cols[col] >> v) & 1) return false;
                if ((sqrs[sq] >> v) & 1) return false;

                rows[row] |= (1 << v);
                cols[col] |= (1 << v);
                sqrs[sq] |= (1 << v);
            }
        }

        return true;
    }
};
