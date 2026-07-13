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
        std::ranges::sort(intervals, [](const auto& a, const auto& b) {
            return a.start < b.start;
        });

        std::priority_queue<int, std::vector<int>,
            std::greater<>> pq;

        for (int i = 0; i < intervals.size(); ++i) {
            if (!pq.empty() && pq.top() >= intervals[i].start) {
                pq.pop();
            }

            pq.push(intervals[i].end);
        }

        return pq.size();
    }
};
