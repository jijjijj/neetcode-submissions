class Solution {
public:
    vector<vector<int>> insert(
        vector<vector<int>>& intervals,
        vector<int>& newInterval) {
        std::vector<std::vector<int>> res;

        const int start = newInterval[0];
        const int end = newInterval[1];

        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] < start) {
                res.emplace_back(intervals[i]);
            } else if (intervals[i][0] > end) {
                res.emplace_back(newInterval);
                std::copy(intervals.begin() + i, intervals.end(),
                    std::back_inserter(res));
                return res;
            } else {
                newInterval[0] = std::min(newInterval[0], intervals[i][0]);
                newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            }
        }
        res.emplace_back(newInterval);

        return res;
    }
};
