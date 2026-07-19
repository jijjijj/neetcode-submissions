class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> s; // index

        int max = 0;
        for (int i = 0; i < heights.size(); ++i) {
            const int h = heights[i];

            int j = i;
            s.push(i);
            while (!s.empty() && heights[s.top()] >= h) {
                j = s.top();
                max = std::max(max, h * (i - j + 1));
                s.pop();
            }
            heights[j] = h;

            s.push(j);
        }

        int j = heights.size();
        while (!s.empty()) {
            max = std::max(max, heights[s.top()] * (j - (int)s.top()));
            s.pop();
        }

        return max;
    }
};
