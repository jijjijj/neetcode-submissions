class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;

        int l = 0;
        int r = heights.size() - 1;

        while (l <= r) {
            max = std::max(
                std::min(heights[l], heights[r]) * (r - l), max);
            if (heights[l] > heights[r]) {
                --r;
            } else {
                ++l;
            }
        }

        return max;
    }
};
