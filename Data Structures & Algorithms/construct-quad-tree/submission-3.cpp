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
            tl ? tl : leaves[tl_v],
            tr ? tr : leaves[tr_v],
            bl ? bl : leaves[bl_v],
            br ? br : leaves[br_v] },
            false, false };
    }

    Node* trueLeaf = new Node{ true, true };
    Node* falseLeaf = new Node{ false, true };
    std::array<Node*, 2> leaves = { falseLeaf, trueLeaf };
};