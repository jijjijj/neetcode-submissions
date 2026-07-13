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
        if (intervals.empty()) return 0;
        
        int max = std::ranges::max(intervals, {},
            [](const Interval& i) { return i.end; }).end;

        std::vector<int> mp(max + 1);

        for (const auto& [start, end] : intervals) {
            ++mp[start];
            --mp[end];
        }

        int total = 0;
        int have = 0;

        for (int i = 0; i <= max; ++i) {
            have += mp[i];

            total = std::max(have, total);
        }

        return total;
    }
};
