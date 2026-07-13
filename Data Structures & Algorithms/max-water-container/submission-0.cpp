class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int max = 0;

        while (left < right) {
            const int vol = (right - left) * std::min(heights[left], heights[right]);
            max = std::max(vol, max);

            if (heights[left] > heights[right]) {
                --right;
            } else {
                ++left;
            }
        }

        return max;
    }
};
