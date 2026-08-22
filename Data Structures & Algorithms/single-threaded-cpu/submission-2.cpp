class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        std::vector<int> t; // enqt, i, proct
        t.resize(tasks.size());
        for (int i = 0; i < tasks.size(); ++i) {
            t[i] = i;
        }
        std::sort(t.begin(), t.end(), [&tasks](const int a, const int b) {
            return tasks[a][0] < tasks[b][0];
        });

        std::vector<int> res;
        using val_t = std::pair<int, int>; // proct, i
        std::priority_queue<val_t,
            std::vector<val_t>, std::greater<>> q;

        int time = 0;
        int i = 0;
        while (!q.empty() || i < t.size()) {
            while (i < t.size() && tasks[t[i]][0] <= time) {
                q.push({ tasks[t[i]][1], t[i] });
                ++i;
            }

            if (q.empty()) {
                time = tasks[t[i]][0];
            } else {
                res.emplace_back(q.top().second);
                time += q.top().first;
                q.pop();
            }
        }
        
        return res;
    }
};