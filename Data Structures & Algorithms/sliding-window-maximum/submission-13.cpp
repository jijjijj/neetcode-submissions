class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();

        std::deque<int> q;

        std::vector<int> res;
        res.reserve(n - k);

        for (int i = 0; i < n; ++i) {
            while (!q.empty() && nums[q.front()] <= nums[i]) q.pop_front();

            q.push_front(i);

            if (q.back() <= i - k) q.pop_back();

            if (i + 1 >= k) {
                res.emplace_back(nums[q.back()]);
            }
        }

        return res;
    }
};
