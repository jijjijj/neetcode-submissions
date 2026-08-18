/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    using val_t = std::tuple<Node*, bool, bool>;

    Node* construct(vector<vector<int>>& grid) {
        auto [node, val, leaf] = build(grid, 0, 0, grid.size());

        if (!node) node = new Node{ val, leaf };

        return node;
    }

private:
    // node, val, leaf
    val_t build(const vector<vector<int>>& grid,
        int x, int y, int n) {
        if (n == 1) return { nullptr, grid[y][x], true };

        auto [tl, tl_v, tl_l] = build(grid, x, y, (n >> 1));
        auto [tr, tr_v, tr_l] = build(grid, x + (n >> 1), y, (n >> 1));
        auto [bl, bl_v, bl_l] = build(grid, x, y + (n >> 1), (n >> 1));
        auto [br, br_v, br_l] = build(grid, x + (n >> 1), y + (n >> 1), (n >> 1));

        if (tl_v == tr_v && bl_v == br_v &&
            tl_v == bl_v && tl_l && tr_l &&
            bl_l && br_l) {
            return { tl, tl_v, tl_l };
        }

        return { new Node{ false, false,
            tl ? tl : new Node{ tl_v, true },
            tr ? tr : new Node{ tr_v, true },
            bl ? bl : new Node{ bl_v, true },
            br ? br : new Node{ br_v, true } },
            false, false };
    }
};