class Solution {
public:
    int findMaximizedCapital(int k, int w,
        vector<int>& profits, vector<int>& capital) {
        std::vector<int> idx(profits.size());
        std::iota(idx.begin(), idx.end(), 0);

        std::sort(idx.begin(), idx.end(),
            [&capital](const int a, const int b) {
                return capital[a] < capital[b];
            });

        std::priority_queue<int> q; // profit, capital
        int i = 0;
        int finished = 0;
        int cap = w;
        while (finished < k) {
            while (i < idx.size() && capital[idx[i]] <= cap) {
                q.push(profits[idx[i]]);
                ++i;
            }

            if (q.empty()) break;

            ++finished;
            cap += q.top();
            q.pop();
        }
        return cap;
    }
};