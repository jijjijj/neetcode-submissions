class Solution {
public:
    using val_t = std::tuple<Node*, bool, bool>;

    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }

private:
    // node, val, leaf
    Node* build(const vector<vector<int>>& grid,
        int xx, int yy, int n) {
        bool same = true;

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                if (grid[yy][xx] != grid[yy + y][xx + x]) {
                    same = false;
                    break;
                }
            }
        }

        if (same) return new Node(grid[yy][xx], true);

        Node* root = new Node{ false, false };

        root->topLeft = build(grid, xx, yy, n / 2);
        root->topRight = build(grid, xx + n / 2, yy, n / 2);
        root->bottomLeft = build(grid, xx, yy + n / 2, n / 2);
        root->bottomRight = build(grid, xx + n / 2, yy + n / 2, n / 2);

        return root;
    }
};