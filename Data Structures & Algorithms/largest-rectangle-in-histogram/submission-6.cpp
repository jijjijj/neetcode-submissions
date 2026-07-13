class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();

        int max = 0;
        
        std::stack<int> ind;  // indices 

        for (int i = 0; i < n; ++i) {
            int popped = 0;
            while (!ind.empty() &&
                heights[ind.top()] > heights[i]) {
                max = std::max(max, heights[ind.top()] * (i - ind.top()));
                ind.pop();
                ++popped;
            }

            for (int j = i - popped; j <= i; ++j) {
                heights[j] = heights[i];
                ind.push(j);
            }
        }

        while (!ind.empty()) {
            max = std::max(max, heights[ind.top()] * (n - ind.top()));
            ind.pop();
        }

        return max;
    }
};
