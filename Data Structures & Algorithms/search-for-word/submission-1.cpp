class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        std::string curr;
        for (int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[0].size(); ++x) {
                if (dfs(board, curr, word, x, y)) return true;
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, std::string& curr,
        const std::string& word, int x, int y) {
        if (x < 0 || y < 0 || x >= board[0].size() ||
            y >= board.size() || board[y][x] == '.' ||
            curr.size() >= word.size()) return false;

        bool found = false;

        curr.push_back(board[y][x]);
        if (curr == word) return true;

        const char tmp = board[y][x];
        board[y][x] = '.';
        found = dfs(board, curr, word, x + 1, y);
        if (!found) found = dfs(board, curr, word, x - 1, y);
        if (!found) found = dfs(board, curr, word, x, y + 1);
        if (!found) found = dfs(board, curr, word, x, y - 1);
        board[y][x] = tmp;
        curr.pop_back();

        return found;
    }
};
