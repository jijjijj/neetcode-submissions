/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        std::ranges::sort(intervals, [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        int last = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[last].end > intervals[i].start) {
                return false;
            } else {
                last = i;
            }
        }

        return true;
    }
};
