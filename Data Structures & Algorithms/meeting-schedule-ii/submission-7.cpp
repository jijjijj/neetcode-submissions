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
        std::vector<int> starts, ends;

        for (const auto& interval : intervals) {
            starts.emplace_back(interval.start);
            ends.emplace_back(interval.end);
        }

        std::ranges::sort(starts);
        std::ranges::sort(ends);

        int max = 0;
        int s = 0;
        int e = 0;
        int have = 0;
        while (s < starts.size()) {
            if (starts[s] < ends[e]) {
                have++;
                s++;
            } else {
                --have;
                ++e;
            }

            max = std::max(max, have);
        }

        return max;
    }
};
