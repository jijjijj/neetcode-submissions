class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        using value_t = std::pair<int, char>;
        std::priority_queue<value_t,
            std::vector<value_t>,
            std::greater<>> q;
        
        std::unordered_map<char, int> freq;
        for (char c : tasks) ++freq[c];

        for (auto [c, f] : freq) {
            for (int i = 0; i < f; ++i)
                q.push({ i * (n + 1), c });
        }

        int time = 0;
        while (!q.empty()) {
            if (q.top().first <= time) {
                q.pop();
            }
            ++time;
        }

        return time;
    }
};
