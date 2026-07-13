class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int vol = 0;
        int startl = left;
        int startr = right;

        while (left <= right) {
            if (height[left] <= height[startl]) {
                vol += height[startl] - height[left];
            } else {
                startl = left;
            }
            if (height[right] <= height[startr]) {
                vol += height[startr] - height[right];
            } else {
                startr = right;
            }

            ++left;
            --right;
        }

        return vol;
    }
};
