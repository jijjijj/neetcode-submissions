class Solution {
public:
    int findMaximizedCapital(int k, int w,
        vector<int>& profits, vector<int>& capital) {
        if (*std::max_element(capital.begin(), capital.end()) <= w) {
            std::nth_element(profits.begin(), profits.begin() + k,
                profits.end());
            return std::accumulate(profits.begin(), profits.begin() + k, 0);
        }
        std::vector<std::pair<int, int>> projects; // index
        for (int i = 0; i < profits.size(); ++i) {
            projects.emplace_back(std::pair{ capital[i], profits[i] });
        }
        std::ranges::sort(projects);

        std::priority_queue<int> q; // profit, capital
        int i = 0;
        int finished = 0;
        int cap = w;
        while (finished < k) {
            while (i < projects.size() && projects[i].first <= cap) {
                q.push(projects[i].second);
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