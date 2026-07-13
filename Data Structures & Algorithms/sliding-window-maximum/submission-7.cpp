class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();

        std::vector<int> result;
        result.reserve(n - k);

        std::deque<int> d; // index

        for (int i = 0; i < n; ++i) {
            while (!d.empty() && nums[d.back()] < nums[i]) {
                d.pop_back();
            }

            d.push_back(i);

            if (d.front() <= i - k) {
                d.pop_front();
            }

            if (i >= k - 1) result.emplace_back(nums[d.front()]);
        }

        return result;
    }
};
