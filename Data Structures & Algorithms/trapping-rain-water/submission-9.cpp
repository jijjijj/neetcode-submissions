class Solution {
public:
    int trap(vector<int>& nums) {
        std::stack<int> s;
        int area = 0;

        for (int i = 0; i < nums.size(); ++i) {
            while (!s.empty() && nums[i] >= nums[s.top()]) {
                const int ind = s.top();
                const int maxh = nums[ind];
                s.pop();
                if (!s.empty()) {
                    area += std::max(std::min(nums[i], nums[s.top()]) -
                        nums[ind], 0) * (i - s.top() - 1);
                }
            }

            s.push(i);
        }

        return area;
    }
};
