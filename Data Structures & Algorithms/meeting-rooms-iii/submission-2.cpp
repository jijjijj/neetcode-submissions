class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        std::ranges::sort(meetings);

        std::vector<int> freq(n);

        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>> q2;

        for (int i = 0; i < n; ++i) {
            q2.push({ 0, i });
        }

        for (int i = 0; i < meetings.size(); ++i) {
            const int s = meetings[i][0];
            const int e = meetings[i][1];

            // std::cout << s << " goes to " <<
            //     q2.top().second << "\n";

            while (q2.top().first < s) {
                auto [f, r] = q2.top();
                q2.pop();
                q2.push({ s, r });
            }

            const auto [free_at, room] = q2.top();
            const int new_end = free_at <= s ? e : free_at + (e - s);
            ++freq[room];
            q2.pop();
            q2.push({ new_end, room });
        }

        int maxi = 0;
        for (int i = 1; i < n; ++i) {
            if (freq[maxi] < freq[i]) maxi = i;
        }

        return maxi;
    }
};