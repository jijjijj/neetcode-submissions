class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        std::sort(intervals.begin(), intervals.end(),
            [](const auto& a, const auto& b) {
                if (a[0] != b[0]) return a[0] < b[0];

                return a[1] < b[1];
            });

        std::vector<int> res;
        res.reserve(queries.size());

        std::unordered_map<int, int> mp;

        for (const int q : queries) {
            if (mp.contains(q)) {
                res.emplace_back(mp[q]);
            } else {
                int l = 0;
                int r = intervals.size() - 1;

                while (l <= r) {
                    const int mid = l + (r - l) / 2;

                    if ((intervals[mid][0] <= q && intervals[mid][1] >= q) ||
                        intervals[mid][0] > q) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }

                // FFFFTTTTTT
                //    rl

                int ans = std::numeric_limits<int>::max();
                while (l < intervals.size() && q >= intervals[l][0] &&
                    q <= intervals[l][1]) {
                    ans = std::min(ans, intervals[l][1] - intervals[l][0] + 1);
                    ++l;
                }

                res.emplace_back(ans == std::numeric_limits<int>::max() ? -1 : ans);
                mp[q] = res.back();
            }
        }

        return res;
    }
};
