class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
            [](const auto& a, const auto& b) {
                // if (a[0] != b[0]) return a[0] < b[0];

                return a[1] < b[1];
            });
        
        int prev = intervals[0][1];
        int rem = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prev) {
                ++rem;
            } else {
                prev = intervals[i][1];
            }
        }
        return rem;
    }
};
