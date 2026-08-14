class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> freq;

        int mx = 0;
        for (char c : tasks) {
            ++freq[c];
            mx = std::max(mx, freq[c]);
        }

        int max_count = 0;
        int total_sum = 0;

        for (auto [_, f] : freq) {
            max_count += (f == mx);
            total_sum += f;
        }

        int to_fit = total_sum - max_count;
        int time = std::max(to_fit, (mx - 1) * (n + 1));

        return time + max_count;
    }
};
