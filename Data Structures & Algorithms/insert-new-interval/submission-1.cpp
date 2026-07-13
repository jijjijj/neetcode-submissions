class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
        vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        while (i < intervals.size() &&
            intervals[i][1] < newInterval[0]) {
            result.emplace_back(intervals[i]);
            ++i;
        }

        int start = newInterval[0];
        int stop = newInterval[1];
        while (i < intervals.size() &&
            newInterval[1] >= intervals[i][0]) {
            start = std::min(start, intervals[i][0]);
            stop = std::max(stop, intervals[i][1]);
            ++i;
        }

        result.emplace_back(std::vector<int>{ start, stop });

        while (i < intervals.size()) {
            result.emplace_back(intervals[i]);
            ++i;
        }

        return result;
    }
};
