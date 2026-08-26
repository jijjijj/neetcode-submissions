class Dsu {
public:
    explicit Dsu(int n) : parent(n, 0), size(n, 1), n{ n } {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    void union_sets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;
        if (size[a] < size[b]) std::swap(a, b);

        --n;

        parent[b] = a;
        size[a] += size[b];
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int find(int v) {
        if (parent[v] == v) return v;

        return parent[v] = find(parent[v]);
    }

    int sz() {
        return n;
    }

private:
    std::vector<int> parent;
    std::vector<int> size;
    int n{};
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        Dsu dsu(accounts.size());
        std::unordered_map<std::string, int> ids;

        for (int j = 0; j < accounts.size(); ++j) {
            const auto& acc = accounts[j];
            for (int i = 1; i < acc.size(); ++i) {
                if (!ids.contains(acc[i])) {
                    ids[acc[i]] = j;
                } else {
                    dsu.union_sets(j, ids[acc[i]]);
                }
            }
        }

        std::unordered_map<int, std::set<std::string>> res;

        for (const auto& [email, acc] : ids) {
            const int idx = dsu.find(acc);

            res[idx].emplace(email);
        }

        vector<vector<string>> ans;

        for (auto& [acc, emls] : res) {
            std::vector<std::string> emails;
            emails.emplace_back(accounts[acc][0]);
            emails.insert(emails.end(), emls.begin(), emls.end());
            ans.emplace_back(std::move(emails));
        }

        return ans;
    }
};