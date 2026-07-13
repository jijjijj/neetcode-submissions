class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int vol = 0;
        int startl = height[left];
        int startr = height[right];

        while (left <= right) {
            if (startl < startr) {
                startl = std::max(startl, height[left]);
                vol += startl - height[left];
                ++left;
            } else {
                startr = std::max(startr, height[right]);
                vol += startr - height[right];
                --right;
            }
        }

        return vol;
    }
};
