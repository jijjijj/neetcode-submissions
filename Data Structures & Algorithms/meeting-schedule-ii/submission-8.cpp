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
            events.emplace_back(interval.start, 1);
            events.emplace_back(interval.end, -1);
        }

        std::ranges::sort(events);

        int have = 0;
        int max = 0;

        for (auto [p, change] : events) {
            have += change;
            max = std::max(max, have);
        }

        return max;
    }
};
