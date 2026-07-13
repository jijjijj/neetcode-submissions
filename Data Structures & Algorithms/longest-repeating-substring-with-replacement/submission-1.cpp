class Solution {
public:
    std::pair<char, int> maxav(int* freq) {
        char maj = 0;
        int repl = 0;
        for (int j = 0; j < 26; ++j) {
            if (freq[j] > freq[maj]) {
                maj = j;
            }
            repl += freq[j];
        }
        repl -= freq[maj];

        return { maj, repl };
    }

    int characterReplacement(string s, int k) {
        int max = 0;

        int freq[26] = {};
        int l = 0;

        for (int i = 0; i < s.size(); ++i) {
            ++freq[s[i] - 'A'];

            std::pair<char, int> state = maxav(freq);
            while (state.second > k) {
                --freq[s[l++] - 'A'];
                state = maxav(freq);
            }

            max = std::max(max, state.second + freq[state.first]);
        }

        return max;
    }
};
