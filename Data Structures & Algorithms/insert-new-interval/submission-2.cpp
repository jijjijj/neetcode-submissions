class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
        vector<int>& newInterval) {
        vector<vector<int>> result;
        
        int start = newInterval[0];
        int stop = newInterval[1];

        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] < start) {
                result.emplace_back(intervals[i]);
            } else if (intervals[i][0] > stop) {
                result.emplace_back(newInterval);
                result.insert(result.end(),
                    intervals.begin() + i, intervals.end());
                return result;
            } else {
                newInterval[0] = std::min(newInterval[0], intervals[i][0]);
                newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            }
        }
        result.emplace_back(newInterval);

        return result;
    }
};
