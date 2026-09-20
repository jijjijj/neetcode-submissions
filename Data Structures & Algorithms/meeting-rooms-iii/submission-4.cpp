class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        std::ranges::sort(meetings);

        std::vector<int> freq(n);

        std::priority_queue<std::pair<long long, int>,
            std::vector<std::pair<long long, int>>,
            std::greater<>> used;  // end_time, room
        std::priority_queue<int, std::vector<int>,
            std::greater<>> avail;

        for (int i = 0; i < n; ++i) {
            avail.push(i);
        }

        for (int i = 0; i < meetings.size(); ++i) {
            const int s = meetings[i][0];
            const int e = meetings[i][1];

            while (!used.empty() &&
                used.top().first <= s) {
                const auto [_, room] = used.top();
                used.pop();
                avail.push(room);
            }

            if (avail.empty()) {
                const auto [time, room] = used.top();
                used.pop();
                ++freq[room];
                used.push({ time + (e - s), room });
            } else {
                const int room = avail.top();
                avail.pop();
                ++freq[room];
                used.push({ e, room });
            }
        }

        return std::max_element(freq.begin(), freq.end()) -
            freq.begin();
    }
};