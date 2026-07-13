class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int bf[128]{};
        int wf[128]{};

        for (const auto& row : board) for(const char ch : row) ++bf[ch];
        for (const char ch : word) ++wf[ch];

        for (int i = 0; i < sizeof(bf) / sizeof(int); ++i) {
            if (bf[i] < wf[i]) return false;
        }

        if (bf[word[0]] > bf[word.back()]) {
            for (int i = 0; i < word.size() / 2; ++i) {
                std::swap(word[i], word[word.size() - i - 1]);
            }
        }

        for (int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[0].size(); ++x) {
                if (dfs(board, 0, word, x, y)) return true;
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, int i,
        const std::string& word, int x, int y) {
        if (x < 0 || y < 0 || x >= board[0].size() ||
            y >= board.size() ||
            word[i] != board[y][x]) return false;
        if (i + 1 == word.size()) return true;

        bool found = false;

        const char tmp = board[y][x];
        board[y][x] = '.';
        found = dfs(board, i + 1, word, x + 1, y) ||
            dfs(board, i + 1, word, x - 1, y) ||
            dfs(board, i + 1, word, x, y + 1) ||
            dfs(board, i + 1, word, x, y - 1);
        board[y][x] = tmp;

        return found;
    }
};
