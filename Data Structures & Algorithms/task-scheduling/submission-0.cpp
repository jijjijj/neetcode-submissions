class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26]{};

        for (const char ch : tasks) ++freq[ch - 'A'];

        int price = 0;

        while (true) {
            int max = 0;

            for (int i = 0; i < 26; ++i) {
                if (freq[i] > freq[max]) {
                    max = i;
                }
            }

            if (!freq[max]) break;

            int iterations = freq[max] - 1;
            freq[max] = 0;

            int fill = n * iterations;

            for (int& f : freq) {
                if (fill > 0) {
                    int sub = std::min(f, std::min(iterations, fill));
                    f -= sub;
                    fill -= sub;
                }
            }

            price += iterations * (n + 1) + 1;
        }

        return price;
    }
};
