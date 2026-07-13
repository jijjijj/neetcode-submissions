class Solution {
public:
    int trap(vector<int>& height) {
        int top_index = 0;

        for (int i = 1; i < height.size(); ++i) {
            if (height[i] > height[top_index]) {
                top_index = i;
            }
        }

        int left = 0;
        int right = height.size() - 1;

        int vol = 0;
        int start = left;
        for (; left <= top_index; ++left) {
            if (height[left] <= height[start]) {
                vol += height[start] - height[left];
            } else {
                start = left;
            }
        }

        start = right;
        for (; right >= top_index; --right) {
            if (height[right] <= height[start]) {
                vol += height[start] - height[right];
            } else {
                start = right;
            }
        }

        return vol;
    }
};
