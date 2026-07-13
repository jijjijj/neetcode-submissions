class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;

        for (const auto& v : nums) {
            q.push(v);

            if (q.size() > k) q.pop();
        }

        return q.top();
    }
};
