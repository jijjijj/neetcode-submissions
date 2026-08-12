class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board,
        vector<string>& words) {
        for (const auto& word : words) add(word);

        for (int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[0].size(); ++x) {
                std::string str;
                dfs(x, y, board, root, str);
            }
        }

        return std::vector<std::string>{ res.begin(), res.end() };
    }

private:
    struct Node {
        Node* children[26]{};
        bool ends{};

        ~Node() {
            for (Node* node : children) delete node;
        }
    };

    void dfs(int x, int y, vector<vector<char>>& board,
        const Node& node, std::string& str) {
        const int w = board[0].size();
        const int h = board.size();

        if (x < 0 || y < 0 || x >= w || y >= h ||
            board[y][x] == '_') return;
    
        const char ch = board[y][x];
        const Node* child = node.children[ch - 'a'];
        if (!child) return;
        str.push_back(ch);

        if (child->ends) res.emplace(str);

        const char tmp = board[y][x];
        board[y][x] = '_';

        dfs(x + 1, y, board, *child, str);
        dfs(x - 1, y, board, *child, str);
        dfs(x, y + 1, board, *child, str);
        dfs(x, y - 1, board, *child, str);

        str.pop_back();

        board[y][x] = tmp;
    }

    void add(const std::string& word) {
        Node* node = &root;

        for (int i = 0; i < word.size(); ++i) {
            const int idx = word[i] - 'a';

            if (!node->children[idx]) {
                node->children[idx] = new Node{};
            }

            node = node->children[idx];
        }

        node->ends = true;
    }

    Node root{};
    std::unordered_set<std::string> res;
};
