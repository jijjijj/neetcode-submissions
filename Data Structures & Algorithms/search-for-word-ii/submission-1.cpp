class Solution {
    struct Node {
        Node* children[26]{};
        bool ends{};

        ~Node() {
            for (auto node : children) delete node;
        }
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const auto& word : words) addWord(word);

        std::unordered_set<std::string> result;

        for (size_t y = 0; y < board.size(); ++y) {
            for (size_t x = 0; x < board[0].size(); ++x) {
                search(board, x, y, result, root);
            }
        }

        return std::vector<std::string>{ result.begin(), result.end() };
    }

private:
    void addWord(const std::string& word) {
        Node* node = &root;

        for (char c : word) {
            Node*& child = node->children[c - 'a'];

            if (!child) child = new Node{};

            node = child;
        }

        node->ends = true;
    }

    void search(std::vector<std::vector<char>>& board, size_t x, size_t y,
        std::unordered_set<std::string>& result, Node& node) {
        const char v = board[y][x];
        
        if (!v) return;

        Node* child = node.children[v - 'a'];

        if (child) {
            current.push_back(v);

            if (child->ends) result.emplace(current);

            board[y][x] = 0;

            if (x < board[0].size() - 1) search(board, x + 1, y, result, *child); 
            if (x) search(board, x - 1, y, result, *child); 
            if (y < board.size() - 1) search(board, x, y + 1, result, *child); 
            if (y) search(board, x, y - 1, result, *child); 

            board[y][x] = v;

            current.pop_back();
        }
    }

    std::string current;
    Node root{};
};
