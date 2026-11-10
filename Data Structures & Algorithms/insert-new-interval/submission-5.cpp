class Solution {
public:
    vector<vector<int>> insert(
        vector<vector<int>>& intervals,
        vector<int>& newInterval) {
        std::vector<std::vector<int>> res;

        for (int i = 0; i < intervals.size(); ++i) {
            if (newInterval[0] <= intervals[i][0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
        }

        for (int i = 0; i < intervals.size(); ++i) {
            if (res.empty() || intervals[i][0] > res.back()[1]) {
                res.emplace_back(intervals[i]);
            } else {
                res.back()[1] = std::max(res.back()[1], intervals[i][1]);
            }
        }

        return res;
    }
};
