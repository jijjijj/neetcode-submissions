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
        std::sort(intervals.begin(), intervals.end(),
            [](const auto& a, const auto& b) {
                return a.start < b.start;
            });
        
        std::priority_queue<int,
            std::vector<int>,
            std::greater<>> q;

        int i = 0;
        while (i < intervals.size()) {
            while (!q.empty() && intervals[i].start >= q.top()) {
                q.pop();
            }

            q.push(intervals[i].end);
            ++i;
        }

        return q.size();
    }
};
