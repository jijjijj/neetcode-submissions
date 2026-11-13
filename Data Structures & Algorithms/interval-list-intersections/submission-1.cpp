class Solution {
public:
    vector<vector<int>> intervalIntersection(
        vector<vector<int>>& first,
        vector<vector<int>>& second) {
        std::vector<std::vector<int>> res;

        int m = first.size();
        int n = second.size();
        int i = 0;
        int j = 0;

        while (i < m && j < n) {
            while (i < m && first[i][1] <= second[j][1]) {
                if (first[i][1] < second[j][0]) {
                    ++i;
                    continue;
                }
                
                const int start = std::max(second[j][0], first[i][0]);
                const int end = std::min(second[j][1], first[i][1]);

                res.push_back({ start, end });
                ++i;
            }

            std::swap(i, j);
            std::swap(m, n);
            std::swap(first, second);
        }

        return res;
    }
};