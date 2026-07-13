#include <ranges>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int max = std::ranges::max(intervals,
            {}, [](const std::vector<int>& i) { return i[0]; })[0];

        std::vector<int> far(max + 1);

        for (const auto& inter : intervals) {
            far[inter[0]] = std::max(far[inter[0]], inter[1]);
        }

        std::vector<std::vector<int>> result;
        int have = -1;
        int start = -1;

        for (int i = 0; i <= max; ++i) {
            if (far[i]) {
                if (start == -1) start = i;
                have = std::max(far[i], have);
            }

            if (have == i) {
                result.emplace_back(
                    std::vector<int>{ start, have });
                start = have = -1;
            }
        }

        if (start != -1)
            result.emplace_back(
                std::vector<int>{ start, have });

        return result;
    }
};
