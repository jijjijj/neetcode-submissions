class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();

        std::vector<int> left(n, 0);
        std::vector<int> right(n, 0);

        std::stack<int> s; // index

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                // std::cout? << "remove " << s.top() << std::endl;
                s.pop();
            }


            left[i] = s.empty() ? -1 : s.top();
            // std::cout << "add " << i << std::endl;
            s.push(i);
        }

        s = {};

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            right[i] = s.empty() ? n : s.top();

            s.push(i);
        }

        int max = 0;
        for (int i = 0; i < n; ++i) {
            const int l = left[i] + 1;
            const int r = right[i] - 1;
            // std::cout << i << ": " << left[i] << " " << right[i] << std::endl;
            max = std::max(max, heights[i] * (r - l + 1));
        }
        return max;
    }
};