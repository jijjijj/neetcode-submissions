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
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }

private:
    Node* build(const vector<vector<int>>& grid,
        int x, int y, int n) {
        if (n == 1) return new Node(grid[y][x], true);

        Node* topLeft = build(grid, x, y, n / 2);
        Node* topRight = build(grid, x + n / 2, y, n / 2);
        Node* bottomLeft = build(grid, x, y + n / 2, n / 2);
        Node* bottomRight = build(grid, x + n / 2, y + n / 2, n / 2);

        if (topLeft->val == topRight->val &&
            bottomLeft->val == bottomRight->val &&
            topLeft->val == bottomLeft->val &&
            topLeft->isLeaf && topRight->isLeaf &&
            bottomLeft->isLeaf && bottomRight->isLeaf) {
            delete topRight;
            delete bottomLeft;
            delete bottomRight;

            return topLeft;
        }

        return new Node{ false, false,
            topLeft, topRight, bottomLeft, bottomRight };
    }
};