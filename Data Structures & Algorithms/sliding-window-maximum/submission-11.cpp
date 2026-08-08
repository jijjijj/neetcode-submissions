class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();

        std::queue<int> q;

        std::vector<int> res;
        res.reserve(n - k);

        for (int i = 0; i < n; ++i) {
            while (!q.empty() &&
                (nums[q.front()] <= nums[i] || q.front() <= i - k)) {
                q.pop();
            }

            q.push(i);

            if (i + 1 >= k) {
                res.emplace_back(nums[q.front()]);
            }
        }

        return res;
    }
};
