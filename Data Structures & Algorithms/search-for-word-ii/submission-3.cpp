class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board,
        vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            add(words[i], i);
        }

        for (int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[0].size(); ++x) {
                dfs(x, y, board, root, words);
            }
        }

        return std::vector<std::string>{ res.begin(), res.end() };
    }

private:
    struct Node {
        Node* children[26]{};
        int word = -1;
        int pass = 0;
        bool ends{};

        ~Node() {
            for (Node* node : children) delete node;
        }
    };

    int dfs(int x, int y, vector<vector<char>>& board,
        const Node& node, const vector<string>& words) {
        const int w = board[0].size();
        const int h = board.size();

        if (x < 0 || y < 0 || x >= w || y >= h ||
            board[y][x] == '_') return 0;
    
        const char ch = board[y][x];
        Node* child = node.children[ch - 'a'];
        if (!child || !child->pass) return 0;
        
        // std::cout << str << std::endl;
        int removed = 0;
        if (child->ends) {
            child->ends = false;
            // node.children
            res.emplace(words[child->word]);
            ++removed;
        }

        const char tmp = board[y][x];
        board[y][x] = '_';

        removed += dfs(x + 1, y, board, *child, words);
        removed += dfs(x - 1, y, board, *child, words);
        removed += dfs(x, y + 1, board, *child, words);
        removed += dfs(x, y - 1, board, *child, words);

        board[y][x] = tmp;

        child->pass -= removed;

        return removed;
    }

    void add(const std::string& word, int id) {
        Node* node = &root;

        for (int i = 0; i < word.size(); ++i) {
            const int idx = word[i] - 'a';

            if (!node->children[idx]) {
                node->children[idx] = new Node{};
            }

            node = node->children[idx];
            ++(node->pass);
        }

        node->word = id;
        node->ends = true;
    }

    Node root{};
    std::unordered_set<std::string> res;
};
