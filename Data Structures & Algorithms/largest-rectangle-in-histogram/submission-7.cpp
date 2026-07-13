class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();

        int max = 0;
        
        std::stack<std::pair<int, int>> ind;  // pos, height 

        for (int i = 0; i < n; ++i) {
            int start = i;
            while (!ind.empty() &&
                ind.top().second >= heights[i]) {
                max = std::max(max, ind.top().second * (i - ind.top().first));
                start = ind.top().first;
                ind.pop();
            }

            ind.push(std::make_pair(start, heights[i]));
        }

        while (!ind.empty()) {
            max = std::max(max, ind.top().second * (n - ind.top().first));
            ind.pop();
        }

        return max;
    }
};
