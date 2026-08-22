class Solution {
public:
    // max freq hashmap
    // prior queue
    // set characters
    std::string reorganizeString(string s) {
        std::unordered_map<char, int> freq;
        for (const char c : s) ++freq[c];

        const char maxf = max_index(freq);
        const int n = s.size();

        if (freq[maxf] > (n + 1) / 2) return "";

        std::string res;

        while (res.size() < s.size()) {
            const char max = max_index(freq);
            res += max;

            const int tmp = freq[max] - 1;
            freq[max] = 0;

            const char second_max = max_index(freq);
            res += second_max;
            --freq[second_max];
            freq[max] = tmp;
        }

        return res;
    }

private:
    char max_index(std::unordered_map<char, int>& freq) {
        char max = 0;
        for (const auto [c, f] : freq) {
            if (f > freq[max]) max = c;
        }
        return max;
    }
};