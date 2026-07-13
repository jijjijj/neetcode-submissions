class SegmentTree {
public:
    explicit SegmentTree(int n) {
        while (n & (n - 1)) {
            ++n;
        }
        _tree.resize(2 * n);
        _n = n;
    }

    void update(int i, int val) {
        i += _n;
        _tree[i] = val;
        i >>= 1;
        while (i) {
            _tree[i] = std::max(_tree[2 * i], _tree[2 * i + 1]);
            i >>= 1;
        }
    }

    int query(int l, int r) {
        if (l > r)
            return 0;

        l += _n;
        r += _n+1;

        int res = std::numeric_limits<int>::min();
        // std::cout << l << " " << r << std::endl;

        while (l < r) {
            if (l & 1) {
                res = std::max(res, _tree[l]);
                ++l;
            }

            if (r & 1) {
                --r;
                res = std::max(res, _tree[r]);
            }

            l >>= 1;
            r >>= 1;
        }
        return res;
    }

private:
    std::vector<int> _tree;
    int _n{};
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> copy = nums;
        std::ranges::sort(copy);

        copy.erase(std::unique(copy.begin(), copy.end()), copy.end());

        std::vector<int> order(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            order[i] = std::ranges::lower_bound(copy, nums[i]) -
                copy.begin();
        }

        SegmentTree seg(nums.size());

        int result = 0;
        for (int num : order) {
            const int max = seg.query(0, num - 1) + 1;
            seg.update(num, max);

            result = std::max(max, result);
        }

        return result;
    }
};
