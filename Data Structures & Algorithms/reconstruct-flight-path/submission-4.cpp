class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto& t : tickets) {
            e[t[0]].emplace_back(t[1]);
        }

        for (auto& [_, adj] : e) {
            std::ranges::sort(adj, std::greater<>{});
        }

        std::vector<std::string> result;

        std::stack<std::string> s;
        s.push("JFK");

        while (!s.empty()) {
            const std::string cur = s.top();
            if (e[cur].empty()) {
                result.emplace_back(cur);
                s.pop();
            } else {
                std::string to = e[cur].back();
                e[cur].pop_back();
                s.push(to);
            }
        }

        std::ranges::reverse(result);
        return result;
    }

    std::unordered_map<std::string,
        std::vector<std::string>> e;
};
