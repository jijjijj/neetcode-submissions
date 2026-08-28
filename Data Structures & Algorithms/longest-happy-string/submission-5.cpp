class Solution {
public:
    // find_max
    // +heap
    // rec
    string longestDiverseString(int a, int b, int c) {
        std::vector<int> freq = { a, b, c };

        std::string res;
        int repeating = -1;

        while (true) {
            const int max = find_max(freq, repeating);
            if (max == -1) break;

            repeating = -1;
            res += static_cast<char>('a' + max);
            --freq[max];

            if (res.size() > 1 &&
                res[res.size() - 2] == res.back()) {
                repeating = max;
            }
        }

        return res;
    }

private:
    int find_max(const std::vector<int>& freq,
        int repeating) {
        int res = -1;
        int max = 0;

        for (int i = 0; i < freq.size(); ++i) {
            if (i == repeating || !freq[i]) continue;

            if (freq[i] > max) {
                res = i;
                max = freq[i];
            }
        }

        return res;
    }
};