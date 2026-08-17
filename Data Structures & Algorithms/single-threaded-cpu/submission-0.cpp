class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        std::vector<std::tuple<int, int, int>> t; // enqt, i, proct
        for (int i = 0; i < tasks.size(); ++i) {
            const auto& task = tasks[i];
            t.emplace_back(std::tuple{
                task[0], i, task[1] });
        }
        std::sort(t.begin(), t.end());

        std::vector<int> res;
        using val_t = std::pair<int, int>; // proct, i
        std::priority_queue<val_t,
            std::vector<val_t>, std::greater<>> q;

        int time = 0;
        int i = 0;
        while (i < t.size()) {
            if (q.empty()) {
                time = std::get<0>(t[i]);
            }
            // q.clear();

            while (true) {
                while (i < t.size() && std::get<0>(t[i]) <= time) {
                    const auto [enq, idx, proc] = t[i];
                    q.push({ proc, idx });
                    ++i;
                }

                if (q.empty()) break;

                res.emplace_back(q.top().second);
                time += q.top().first;
                q.pop();
            }
        }
        
        return res;
    }
};