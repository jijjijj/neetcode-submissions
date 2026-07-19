class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();

        std::vector<int> left(n, 0);
        std::vector<int> right(n, 0);

        std::stack<int> s; // index

        for (int i = 0; i < n; ++i) {
            if (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            left[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }

        s = {};

        for (int i = n - 1; i >= 0; --i) {
            if (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            right[i] = s.empty() ? n : s.top();

            s.push(i);
        }

        int max = 0;
        for (int i = 0; i < n; ++i) {
            const int l = left[i] + 1;
            const int r = right[i] - 1;

            max = std::max(max, heights[i] * (r - l + 1));
        }
        return max;
    }
};