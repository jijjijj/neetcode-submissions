class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> q(stones.begin(), stones.end());

        while (q.size() > 1) {
            const int a = q.top(); q.pop();
            const int b = q.top(); q.pop();

            if (a != b) q.push(a - b);
        }

        return q.empty() ? 0 : q.top();
    }
};
