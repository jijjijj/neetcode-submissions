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

private:
    int find(int v) {
        if (v == parent[v]) return v;

        return parent[v] = find(parent[v]);
    }

    std::vector<int> parent;
    std::vector<int> size;
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        const int max = *std::max_element(nums.begin(), nums.end());

        std::vector<int> p = primes(max);

        Dsu dsu(max + 1);

        std::unordered_set<int> factors;
        for (int i = 0; i < nums.size(); ++i) {
            int pr = 0;
            int v = nums[i];

            std::vector<int> f;
            while (pr < p.size() && p[pr] < v) {
                int cur = 0;
                while (!(v % p[pr])) {
                    v /= p[pr];
                    cur = p[pr];
                }

                ++pr;

                if (cur) {
                    factors.emplace(cur);
                    f.emplace_back(cur);
                }
            }

            if (v > 1 || nums[i] == 1) {
                f.emplace_back(v);
                factors.emplace(v);
            }

            for (int j = 1; j < f.size(); ++j) {
                dsu.union_sets(f[j], f[j - 1]);
            }
        }

        if (factors.empty()) return false;

        return dsu.count(*factors.begin()) == factors.size();
    }

private:
    std::vector<int> primes(int n) {
        std::vector<int> e(n + 1);

        std::vector<int> res;

        for (int i = 2; i <= n; ++i) {
            if (!e[i]) {
                res.emplace_back(i);

                for (int x = i; x <= n; x += i) {
                    e[x] = true;
                }
            }
        }

        return res;
    }
};