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
        std::unordered_map<std::string,
            std::pair<int, std::string>> ids;

        for (const auto& acc : accounts) {
            for (int i = 1; i < acc.size(); ++i) {
                if (!ids.contains(acc[i])) {
                    ids[acc[i]] = { ids.size(), acc[0] };
                }
            }
        }

        Dsu dsu(ids.size());

        for (const auto& acc : accounts) {
            for (int i = 2; i < acc.size(); ++i) {
                dsu.union_sets(ids[acc[1]].first, ids[acc[i]].first);
            }
        }

        std::vector<std::pair<std::string,
            std::set<std::string>>> res(ids.size());

        for (const auto& [email, data] : ids) {
            const int idx = dsu.find(data.first);

            if (res[idx].first.empty()) {
                res[idx].first = data.second;
            }

            res[idx].second.emplace(email);
        }

        vector<vector<string>> ans;

        for (auto& fuck : res) {
            if (fuck.first.empty()) continue;
            std::vector<std::string> emails;
            emails.emplace_back(fuck.first);
            emails.insert(emails.end(), fuck.second.begin(), fuck.second.end());
            ans.emplace_back(std::move(emails));
        }

        return ans;
    }
};