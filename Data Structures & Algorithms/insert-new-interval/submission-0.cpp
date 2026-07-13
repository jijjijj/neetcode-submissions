class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
        vector<int>& newInterval) {
        std::vector<std::vector<int>> res;

        int min = newInterval[0];
        int max = newInterval[1];
        bool inside = false;

        int prev_end = 0;

        for (const auto& inter : intervals) {
            if (inter[0] <= newInterval[0] &&
                newInterval[0] <= inter[1]) {
                min = inter[0];
                inside = true;
            } else if (newInterval[0] > prev_end &&
                newInterval[0] < inter[0]) {
                min = newInterval[0];
                inside = true;
            }
            if (!inside) res.emplace_back(inter);

            if (inter[0] <= newInterval[1] &&
                newInterval[1] <= inter[1]) {
                max = inter[1];
                res.emplace_back(std::vector{ min, max });
                inside = false;
            } else if (newInterval[1] > prev_end &&
                newInterval[1] < inter[0]) {
                max = newInterval[1];
                res.emplace_back(std::vector{ min, max });
                inside = false;
                res.emplace_back(inter);
            }

            prev_end = inter[1];
        }

        return res;
    }
};
