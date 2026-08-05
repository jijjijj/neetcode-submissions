class SegmentTree {
public:
    explicit SegmentTree(int n) {
        while ((n & (n - 1))) {
            ++n;
        }

        _n = n;
        _data.resize(n * 2);
    }

    void update(int i, int v) {
        i += _n;
        _data[i] = v;
        i >>= 1;

        while (i) {
            _data[i] = std::max(_data[i << 1],
                _data[(i << 1) | 1]);
            
            i >>= 1;
        }
    }

    // [l, r)
    int query(int l, int r) {
        int max = std::numeric_limits<int>::min();

        l += _n;
        r += _n;

        while (l < r) {
            if (l & 1) {
                max = std::max(max, _data[l]);
                ++l;
            }

            if (r & 1) {
                --r;
                max = std::max(max, _data[r]);
            }

            l >>= 1;
            r >>= 1;
        }

        return max;
    }

private:
    int _n = 0;
    std::vector<int> _data;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> res;
        res.reserve(nums.size() - k);

        SegmentTree tree(nums.size());
        for (int i = 0; i < nums.size(); ++i) tree.update(i, nums[i]);

        for (int i = k - 1; i < nums.size(); ++i) {
            res.emplace_back(tree.query(i - k + 1, i + 1));
        } 

        return res;
    }
};
