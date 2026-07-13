class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> result;
        result.reserve(nums.size() - k);

        std::priority_queue<std::pair<int, int>> q; // index, val

        for (int i = 0; i < nums.size(); ++i) {
            q.push(std::make_pair(nums[i], i));

            while (q.top().second <= i - k) {
                q.pop();
            }

            if (i + 1 >= k) {
                result.emplace_back(q.top().first);
            }
        } 

        return result;
    }
};
