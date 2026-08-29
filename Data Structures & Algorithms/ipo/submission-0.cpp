class Solution {
public:
    int findMaximizedCapital(int k, int w,
        vector<int>& profits, vector<int>& capital) {
        std::vector<std::pair<int, int>> projects; // capital, profit
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