class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        int total = 0;
        int last = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (last <= intervals[i][0]) {
                last = intervals[i][1];
            } else {
                ++total;
                last = std::min(last, intervals[i][1]);
            }
        }

        return total;
    }
};
