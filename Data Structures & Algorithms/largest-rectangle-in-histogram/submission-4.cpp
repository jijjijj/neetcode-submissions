class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const size_t n = heights.size();

        int max = 0;
        int last_h = 0;

        std::array<int, 1001> av{};

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = heights[i] + 1; j <= last_h; ++j) av[j] = 0;
            for (size_t j = 0; j <= heights[i]; ++j) {
                ++av[j];

                const int area = j * av[j];

                max = std::max(max, area);
            }
            last_h = heights[i];
        }
        
        return max;
    }
};
