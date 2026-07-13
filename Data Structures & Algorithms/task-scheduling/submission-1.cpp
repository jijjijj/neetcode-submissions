class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26]{};

        for (char c : tasks) ++freq[c - 'A'];

        std::priority_queue<int> max;

        for (int f : freq) if (f) max.push(f);

        std::queue<std::pair<int, int>> cd; // cnt, time

        int time = 0;
        while (!max.empty() || !cd.empty()) {
            ++time;

            if (max.empty()) {
                time = cd.front().second;
            } else {
                int cnt = max.top() - 1;
                max.pop();

                if (cnt > 0) cd.push(std::pair{ cnt, time + n });
            }

            if (!cd.empty() && cd.front().second == time) {
                max.push(cd.front().first);
                cd.pop();
            }
        }
        return time;
    }
};
