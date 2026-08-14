class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        using value_t = std::tuple<int, int>;
        std::priority_queue<int> pq;
        std::queue<std::pair<int, int>> q;
        
        std::unordered_map<char, int> freq;
        for (char c : tasks) ++freq[c];
        for (auto [_, f] : freq) pq.push(f);

        int time = 0;
        while (!q.empty() || !pq.empty()) {
            ++time;

            if (pq.empty()) {
                time = q.front().second;
            } else {
                const int cnt = pq.top() - 1;
                if (cnt > 0) {
                    q.push({ cnt, time + n });
                }
                pq.pop();
            }

            if (q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
