class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        const int n = accounts.size();

        std::unordered_map<std::string, int> ids;
        for (int j = 0; j < n; ++j) {
            const auto& acc = accounts[j];
            for (int i = 1; i < acc.size(); ++i) {
                if (!ids.contains(acc[i])) {
                    acc_by_id[ids.size()] = j;
                    eee.emplace_back(acc[i]);
                    ids[acc[i]] = ids.size();
                }
            }
        }

        std::vector<std::vector<int>> e(ids.size());
        for (int j = 0; j < accounts.size(); ++j) {
            for (int i = 2; i < accounts[j].size(); ++i) {
                const int email1 = ids[accounts[j][i]];
                const int email2 = ids[accounts[j][i - 1]];
                e[email1].emplace_back(email2);
                e[email2].emplace_back(email1);
            }
        }

        for (int i = 0; i < ids.size(); ++i) {
            if (vis.contains(i)) continue;

            dfs(i, -1, acc_by_id[i], accounts, e);
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

private:
    void dfs(int v, int p, int acc,
        const vector<vector<string>>& accounts,
        const std::vector<std::vector<int>>& e) {
        res[acc].emplace(eee[v]);
        vis.emplace(v);

        for (const int to : e[v]) {
            if (to == p || vis.contains(to)) continue;

            dfs(to, v, acc, accounts, e);
        }
    }

    std::unordered_map<int, int> acc_by_id;
    std::unordered_map<int,
        std::set<std::string>> res;
    std::unordered_set<int> vis;
    std::vector<std::string> eee;
};