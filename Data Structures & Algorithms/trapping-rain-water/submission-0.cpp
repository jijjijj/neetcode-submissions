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

        while (!height[left]) ++left;
        while (!height[right]) --right;

        // std::cout << left << " " << right << " " << top_index << std::endl;

        int vol = 0;
        int minus = 0;
        int start = left;
        for (++left; left <= top_index; ++left) {
            if (height[left] >= height[start]) {
                // std::cout << "commit at " << left << " = " << height[start] * (left - start - 1) - minus << std::endl;
                vol += height[start] * (left - start - 1) - minus;
                start = left;
                minus = 0;
            } else {
                minus += height[left];
            }
        }

        // std::cout << vol << std::endl;

        minus = 0;
        start = right;
        for (--right; right >= top_index; --right) {
            if (height[right] >= height[start]) {
                vol += height[start] * (start - right - 1) - minus;
                start = right;
                minus = 0;
            } else {
                minus += height[right];
            }
        }

        return vol;
    }
};
