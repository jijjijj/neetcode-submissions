class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        using value_t = std::tuple<int, int>;
        std::priority_queue<value_t,
            std::vector<value_t>,
            std::greater<>> q;
        
        std::unordered_map<char, int> freq;
        for (char c : tasks) ++freq[c];

        for (auto [_, f] : freq) {
            q.push({ 0, f });
        }

        int time = 0;
        while (!q.empty()) {
            const auto [t, l] = q.top();
            if (t > time) time = t;
            if (t <= time) {
                q.pop();
                if (l > 1) q.push({ t + n + 1, l - 1 });
            }
            ++time;
        }

        return time;
    }
};
