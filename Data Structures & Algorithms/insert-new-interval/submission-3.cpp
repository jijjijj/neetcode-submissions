class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
        vector<int>& newInterval) {
        vector<vector<int>> result;
        
        int left = 0;
        int right = intervals.size() - 1;

        while (left <= right) {
            const int mid = left + (right - left) / 2;

            if (intervals[mid][0] >= newInterval[0]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        intervals.insert(intervals.begin() + left, newInterval);

        for (int i = 0; i < intervals.size(); ++i) {
            // std::cout << intervals[i][0] << " " << intervals[i][1] << std::endl;
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
