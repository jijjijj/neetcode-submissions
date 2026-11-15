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

        for (const auto& i : intervals) {
            mp[i.start] += 1;
            mp[i.end] -= 1;
        }

        int mx = 0;
        int cur = 0;
        for (const auto [_, e] : mp) {
            cur += e;
            mx = std::max(mx, cur);
        }

        return mx;
    }
};
