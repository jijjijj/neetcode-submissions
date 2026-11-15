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
        std::vector<std::pair<int, int>> events;

        for (const auto& interval : intervals) {
            events.push_back({ interval.start, 1 });
            events.push_back({ interval.end, -1 });
        }

        std::ranges::sort(events);

        int cur = 0;
        int ans = 0;
        
        for (const auto& [_, e] : events) {
            cur += e;
            ans = std::max(ans, cur);
        }

        return ans;
    }
};
