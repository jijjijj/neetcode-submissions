class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int, int>> s; // index, height
        const int n = heights.size();

        int max = 0;
        for (int i = 0; i < n; ++i) {
            // s.push(std::make_pair(i, heights[i]));

            int last = i;
            while (!s.empty() && s.top().second > heights[i]) {
                last = s.top().first;
                max = std::max(max, (i - last) * s.top().second);
                s.pop();
            }

            // max = std::max(max, heights[i]);
            // if (!s.empty()) max = std::max(max, (i - s.top().first + 1) * s.top().second);

            s.push(std::make_pair(last, heights[i]));
        }

        while (!s.empty()) {
            max = std::max(max, (n - (s.top().first)) * s.top().second);
            s.pop();
        }

        return max;
    }
};
