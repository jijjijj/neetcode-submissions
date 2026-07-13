class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::map<int, int> mp; // point, balance

        for (const auto& interval : intervals) {
            ++mp[interval[0]];
            --mp[interval[1]];
        }

        std::vector<std::vector<int>> result;
        std::vector<int> interval;
        int have = 0;

        for (auto [i, bal] : mp) {
            if (interval.empty()) {
                interval.emplace_back(i);
            }

            have += bal;

            if (have == 0) {
                interval.emplace_back(i);
                result.emplace_back(std::move(interval));
            }
        }

        return result;
    }
};
