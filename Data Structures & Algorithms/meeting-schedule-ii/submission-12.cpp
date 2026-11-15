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
            std::greater<int>> q;

        // int mx = 0;
        // int i = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            if (!q.empty() && q.top() <= intervals[i].start) {
                q.pop();
            }

            q.push(intervals[i].end);
            // mx = std::max(mx, (int)q.size());
        }

        return q.size();
    }
};
