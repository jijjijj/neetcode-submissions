#include <ranges>

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        std::unordered_map<int, int> freq;

        for (int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[0].size(); ++x) {
                ++freq[board[y][x]];
            }
        }

        std::unordered_map<int, int> ref;
        for (const char c : word) ++ref[c];

        for (const auto [c, f] : ref) {
            if (freq[c] < f) return false;
        }

        if (freq[word.front()] > freq[word.back()])
            std::ranges::reverse(word);

        for (int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[0].size(); ++x) {
                if (dfs(board, x, y, 0, word)) return true;
            }
        }

        return false;
    }

private:
    bool dfs(std::vector<std::vector<char>>& board,
        int x, int y, int i, const std::string& word) {
        if (i == word.size()) return true;

        const int w = board[0].size();
        const int h = board.size();

        if (x < 0 || y < 0 || x >= w || y >= h ||
            board[y][x] == '.' || board[y][x] != word[i])
            return false;

        const char tmp = board[y][x];

        board[y][x] = '.';
        const bool res = dfs(board, x + 1, y, i + 1, word) ||
            dfs(board, x - 1, y, i + 1, word) ||
            dfs(board, x, y + 1, i + 1, word) ||
            dfs(board, x, y - 1, i + 1, word);
        board[y][x] = tmp;

        return res;
    }
};
