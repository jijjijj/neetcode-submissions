class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        res.push_back({});

        for (int j = 0; j < k; ++j) {
            std::vector<std::vector<int>> nw;
            for (const auto& c : res) {
                const int first = c.empty() ? 1 : c.back() + 1;
                for (int i = first; i <= n - k + j + 1; ++i) {
                    std::vector<int> copy = c;
                    copy.emplace_back(i);
                    nw.emplace_back(std::move(copy));
                }
            }
            res = std::move(nw);
        }

        return res;
    }
};