class SegmentTree {
public:
    SegmentTree(int n, std::vector<int> heights)
        : _heights(std::move(heights)) {
        while ((n - 1) & n) ++n;
        
        _data.resize(2 * n + 1);
        _n = n;
    }

    void update(int i, int val) {
        i += _n;

        _data[i] = val;
        i >>= 1;

        while (i) {
            const int li = i << 1;
            const int ri = (i << 1) | 1;

            _data[i] = _heights[_data[li]] > _heights[_data[ri]]
                ? _data[ri] : _data[li];

            i >>= 1;
        }
    }

    // search [l, r) range
    int query(int l, int r) const {
        int resi = l;

        if (l > r) return 0;

        l += _n;
        r += _n;

        while (l < r) {
            if (l & 1) {
                if (_heights[_data[l]] < _heights[resi]) resi = _data[l];
                ++l;
            }

            if (r & 1) {
                --r;
                if (_heights[_data[r]] < _heights[resi]) resi = _data[r];
            }

            l >>= 1;
            r >>= 1;
        }

        return resi;
    }

    void print() {
        for (int x : _data) std::cout << x << " ";
    }

private:
    std::vector<int> _data;
    std::vector<int> _heights;
    int _n{};
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        SegmentTree tree(heights.size(), heights);
        
        for (int i = 0; i < heights.size(); ++i) {
            tree.update(i, i);
        }
        // tree.print();
        return max_area(0, heights.size() - 1, tree, heights);
    }

private:
    // [l, r]
    int max_area(int l, int r, const SegmentTree& tree,
        const std::vector<int>& heights) {
        if (l > r) return 0;

        const int mid = tree.query(l, r + 1);

        return std::max({
            (r - l + 1) * heights[mid],
            max_area(l, mid - 1, tree, heights),
            max_area(mid + 1, r, tree, heights)
        });
    }
};
