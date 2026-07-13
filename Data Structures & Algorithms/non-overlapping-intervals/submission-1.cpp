class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
                return a[1] < b[1];
            });

        int total = 0;
        int last = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= last) {
                last = intervals[i][1];
            } else {
                ++total;
            }
        }

        return total;
    }
};
