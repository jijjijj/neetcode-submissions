class Solution {
public:
    vector<vector<int>> intervalIntersection(
        vector<vector<int>>& first,
        vector<vector<int>>& second) {
        std::map<int, int> events;

        for (const auto& f : first) {
            events[f[0]] += 1;
            events[f[1] + 1] -= 1;
        }

        for (const auto& f : second) {
            events[f[0]] += 1;
            events[f[1] + 1] -= 1;
        }

        std::vector<std::vector<int>> res;

        int cur = 0;
        for (auto [c, e] : events) {
            if (cur == 2) {
                res.back()[1] = c - 1;
            }
            if (cur + e == 2) {
                res.emplace_back(std::vector{ c, 0 });
            }

            cur += e;
        }

        return res;
    }
};