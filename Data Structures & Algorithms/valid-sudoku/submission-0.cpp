class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (size_t i = 0; i < 9; ++i) {
            std::array<int, 9> num = {};

            for (size_t j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;

                if (num[board[i][j] - '1']++ > 0) {
                    // std::cout << "row " << i << std::endl;
                    return false;
                }
            }
        }

        for (size_t i = 0; i < 9; ++i) {
            std::array<int, 9> num = {};

            for (size_t j = 0; j < 9; ++j) {
                if (board[j][i] == '.') continue;

                if (num[board[j][i] - '1']++ > 0) {
                    // std::cout << "col " << i << std::endl;

                    return false;
                }
            }
        }

        for (size_t i = 0; i < 9; ++i) {
            std::array<int, 9> num = {};

            const size_t off_x = (i % 3) * 3;
            const size_t off_y = (i / 3) * 3;

            for (size_t j = 0; j < 9; ++j) {
                const char val = board[off_y + j / 3][off_x + (j % 3)];
                if (val == '.') continue;

                if (num[val - '1']++ > 0) {
                    // std::cout << "square " << i << std::endl;

                    return false;
                }
            }
        }

        return true;
    }
};
