bool operator<(const std::vector<int>& a, const std::vector<int>& b) {
    return std::tie(a[0], a[1]) < std::tie(b[0], b[1]);
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        
        std::vector<std::vector<int>> result;

        for (int i = 0; i < intervals.size(); ++i) {
            if (result.empty() || result.back()[1] < intervals[i][0]) {
                result.emplace_back(intervals[i]);
            } else {
                result.back()[0] = std::min(result.back()[0], intervals[i][0]);
                result.back()[1] = std::max(result.back()[1], intervals[i][1]);
            }
        }

        return result;
    }
};
