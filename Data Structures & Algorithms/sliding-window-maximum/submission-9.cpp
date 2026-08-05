class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const auto comp = [&nums](const int a, const int b) {
            return nums[a] < nums[b];
        };

        std::priority_queue<int, std::vector<int>, decltype(comp)> q(comp);

        std::vector<int> res;
        res.reserve(nums.size() - k);

        for (int i = 0; i < nums.size(); ++i) {
            q.push(i);
            while (q.size() > k && q.top() <= (i - k)) {
                q.pop();
            }
            if (i >= k - 1) res.emplace_back(nums[q.top()]);
        }

        return res;
    }
};
