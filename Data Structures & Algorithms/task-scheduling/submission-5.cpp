class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        using value_t = std::tuple<int, char, int>;
        std::priority_queue<value_t,
            std::vector<value_t>,
            std::greater<>> q;
        
        std::unordered_map<char, int> freq;
        for (char c : tasks) ++freq[c];

        for (auto [_, f] : freq) {
            q.push({ 0, _, f });
        }

        int time = 0;
        while (!q.empty()) {
            const auto [t, c, l] = q.top();
            if (t <= time) {
                q.pop();
                if (l > 1) q.push({ t + n + 1, c, l - 1 });
            }
            ++time;
        }

        return time;
    }
};
