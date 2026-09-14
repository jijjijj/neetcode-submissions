// class Dsu {
// public:
//     explicit Dsu(int n) : parent(n), size(n, 1) {
//         std::iota(parent.begin(), parent.end(), 0);
//     }

//     void union_sets(int a, int b) {
//         a = find(a);
//         b = find(b);

//         if (a == b) return;
//         if (size[a] < size[b]) std::swap(a, b);

//         parent[b] = a;
//         size[a] += size[b];
//     }

//     int count(int v) {
//         return size[find(v)];
//     }

//     int find(int v) {
//         if (v == parent[v]) return v;

//         return parent[v] = find(parent[v]);
//     }

// private:
//     std::vector<int> parent;
//     std::vector<int> size;
// };

class Solution {
public:
    // bf
    // +dsu + SPF
    // dsu + factorization
    // SPF + DFS/BFS
    bool canTraverseAllPairs(vector<int>& nums) {
        const int max = *std::max_element(nums.begin(), nums.end());
        const int n = nums.size();

        std::vector<int> spf(max + 1);
        for (int i = 2; i * i <= max; ++i) {
            if (spf[i]) continue;

            for (int x = i * i; x <= max; x += i) {
                if (!spf[x]) spf[x] = i;
            }
        }

        // Dsu dsu(max + n + 1);

        std::vector<std::vector<int>> e(max + n + 1);
        // std::unordered_map<int, int> factors;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            
            if (!spf[v] && v > 1) {
                e[i].emplace_back(n + v);
                e[n + v].emplace_back(i);
                // dsu.union_sets(i, n + v);
                continue;
            }

            while (v > 1) {
                int p = spf[v] ? spf[v] : v;
                e[i].emplace_back(n + p);
                e[n + p].emplace_back(i);
                // dsu.union_sets(i, n + p);
                while (v % p == 0) v /= p;
            }
        }
        
        std::unordered_set<int> vis;
        std::queue<int> q;
        q.push(0);
        vis.emplace(0);
        
        while (!q.empty()) {
            const int v = q.front();
            q.pop();

            for (const int to : e[v]) {
                if (vis.contains(to)) continue;
                vis.emplace(to);

                q.push(to);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!vis.contains(i)) return false;
        }

        return true;
    }
};