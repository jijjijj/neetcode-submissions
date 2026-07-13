class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int, int>> s; // index, height
        const int n = heights.size();

        int max = 0;
        for (int i = 0; i < n; ++i) {
            int last = i;
            while (!s.empty() && s.top().second >= heights[i]) {
                last = s.top().first;
                s.pop();
                max = std::max(max, (i - last + 1) * heights[i]);
            }

            max = std::max(max, heights[i]);
            if (!s.empty()) max = std::max(max, (i - s.top().first + 1) * s.top().second);

            s.push(std::make_pair(last, heights[i]));

            // std::cout << i << ": ";
            // auto c = s;
            // while (!c.empty()) {
            //     std::cout << "(" << c.top().first << ", " << c.top().second << ") ";
            //     c.pop();
            // }
            // std::cout << std::endl;
        }

        return max;
    }
};
