class SegmentTree {
public:
    explicit SegmentTree(int n) {
        int N = 1;

        while (n) {
            n >>= 1;
            N <<= 1;
        }

        this->n = N;
        data.resize(2 * N + 1);
    }

    void update(int l, int val) {
        l += n;
        data[l] = val;
        l >>= 1;

        while (l) {
            data[l] = std::max(data[l << 1], data[(l << 1) | 1]);
            l >>= 1;
        }
    }

    int query(int l, int r) {
        // [l, r)
        l += n;
        r += n;

        int res = 0;
        // <= ?
        while (l < r) {
            if (r & 1) {
                --r;
                res = std::max(res, data[r]);
            }

            if (l & 1) {
                res = std::max(res, data[l]);
                ++l;
            }

            l >>= 1;
            r >>= 1;
        }

        return res;
    }

private:
    int n{};
    std::vector<int> data;
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<std::pair<int, int>> copy;
        copy.reserve(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            copy.emplace_back(std::pair{ nums[i], i });
        }

        std::sort(copy.begin(), copy.end(), [](const auto& a, const auto& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        SegmentTree tree(copy.size());

        int lis = 1;

        for (const auto [_, i] : copy) {
            const int cur = tree.query(0, i) + 1;
            tree.update(i, cur);

            // std::cout << _ << " " << i << " " << cur << std::endl;

            lis = std::max(lis, cur);
        }

        return lis;
    }
};
