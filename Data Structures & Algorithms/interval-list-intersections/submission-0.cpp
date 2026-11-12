class Solution {
public:
    vector<vector<int>> intervalIntersection(
        vector<vector<int>>& first,
        vector<vector<int>>& second) {
        std::vector<std::pair<int, int>> events; // <coord, event>
        events.resize(first.size() + second.size());

        int i = 0;
        int j = 0;

        const int m = first.size() * 2;
        const int n = second.size() * 2;

        while (i < m || j < n) {
            int f = i < m ? first[i / 2][i % 2] : INT_MAX;
            int s = j < n ? second[j / 2][j % 2] : INT_MAX;
            int e = i;
            if (f < s || (f == s ? ((i % 2) < (j % 2)) : false)) {
                ++i;
            } else {
                e = j;
                ++j;
                std::swap(f, s);
            }

            events.emplace_back(std::pair{
                f, (e & 1) ? -1 : 1 });
        }

        std::vector<std::vector<int>> res;

        int cur = 0;
        int start = -1;
        for (int i = 0; i < events.size(); ++i) {
            const int event = events[i].second;
            cur += event;

            if (cur == 2) {
                start = events[i].first;
            } else if (cur == 1 && start != -1) {
                res.push_back({ start, events[i].first });
                start = -1;
            }
        }

        return res;
    }
};