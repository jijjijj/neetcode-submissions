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
        std::map<int, int> mp;

        for (const auto& interval : intervals) {
            ++mp[interval.start];
            --mp[interval.end];
        }

        int total = 0;
        int have = 0;

        for (auto [p, balance] : mp) {
            have += balance;

            total = std::max(total, have);
        }

        return total;
    }
};
