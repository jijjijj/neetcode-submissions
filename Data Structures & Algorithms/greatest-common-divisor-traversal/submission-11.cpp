class Dsu {
public:
    explicit Dsu(int n) : parent(n), size(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    void union_sets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;
        if (size[a] < size[b]) std::swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }

    int count(int v) {
        return size[find(v)];
    }

    int find(int v) {
        if (v == parent[v]) return v;

        return parent[v] = find(parent[v]);
    }

private:
    std::vector<int> parent;
    std::vector<int> size;
};

class Solution {
public:
    // +bf
    // +dsu + SPF
    // dsu + factorization
    // +SPF + DFS/BFS
    bool canTraverseAllPairs(vector<int>& nums) {
        const int max = *std::max_element(nums.begin(), nums.end());
        const int n = nums.size();

        Dsu dsu(n);

        std::unordered_map<int, int> factors;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            int f = 2;
            while (f * f <= v) {
                if (v % f == 0) {
                    int p = f;
                    if (factors.contains(p)) {
                        dsu.union_sets(factors[p], i);
                    } else {
                        factors[p] = i;
                    }
                    while (v % p == 0) v /= p;
                }
                ++f;
            }

            if (v > 1) {
                if (factors.contains(v)) {
                    dsu.union_sets(factors[v], i);
                } else {
                    factors[v] = i;
                }
            }
        }

        return dsu.count(0) == n;
    }
};