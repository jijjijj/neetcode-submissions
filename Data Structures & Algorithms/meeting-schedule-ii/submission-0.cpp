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
    int minMeetingRooms(vector<Interval>& intervals) {
        std::ranges::sort(intervals, [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        int total = 1;
        int end = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start >= intervals[end].end) {
                end = i;
            } else {
                ++total;
                if (intervals[i].end < intervals[end].end) {
                    end = i;
                }
            }
        }

        return total;
    }
};
