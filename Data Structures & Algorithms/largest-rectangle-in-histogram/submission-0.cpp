class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const size_t n = heights.size();
        std::vector<std::array<int, 1001>> av(n,
            std::array<int, 1001>{});

        int max = 0;

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j <= heights[i]; ++j) {
                if (i > 0) {
                    av[i][j] += av[i - 1][j];
                }
                ++av[i][j];

                const int area = j * av[i][j];

                max = std::max(max, area);
            }
        }
        
        return max;
    }
};
