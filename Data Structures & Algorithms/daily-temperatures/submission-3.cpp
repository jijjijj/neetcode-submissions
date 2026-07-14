class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        std::stack<int> s; // index

        std::vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                s.pop();
            }

            if (!s.empty()) res[i] = s.top() - i;

            if (s.empty() || nums[s.top()] >= nums[i]) {
                s.push(i);
            }
        }
        return res;
    }
};
