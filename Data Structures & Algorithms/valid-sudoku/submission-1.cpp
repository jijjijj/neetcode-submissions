class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::array<uint16_t, 9> rows = {};
        std::array<uint16_t, 9> cols = {};
        std::array<uint16_t, 9> sqs = {};

        for (size_t i = 0; i < 9; ++i) {
            for (size_t j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                const unsigned val = board[i][j] - '1';

                if (((rows[i] >> val) & 1) ||
                    ((cols[j] >> val) & 1) ||
                    ((sqs[i / 3 * 3 + j / 3] >> val) & 1)) {
                    return false;
                }

                rows[i] |= (1 << val);
                cols[j] |= (1 << val);
                sqs[i / 3 * 3 + j / 3] |= (1 << val);
            }
        }

        return true;
    }
};
