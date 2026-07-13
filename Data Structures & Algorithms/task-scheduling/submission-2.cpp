class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26]{};

        for (char c : tasks) ++freq[c - 'A'];

        std::ranges::sort(freq);

        int maxf = freq[25] - 1;
        int idle = maxf * n;

        for (int i = 24; i >= 0; --i) {
            idle -= std::min(freq[i], maxf);
        }

        return std::max(0, idle) + tasks.size();
    }
};
