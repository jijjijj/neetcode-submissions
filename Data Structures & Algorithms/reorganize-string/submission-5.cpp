class Solution {
public:
    // +max freq hashmap
    // +prior queue
    // set characters
    std::string reorganizeString(string s) {
        std::vector<int> freq(26, 0);
        for (const char c : s) ++freq[c - 'a'];

        const int maxi = std::max_element(freq.begin(),
            freq.end()) - freq.begin();
        const int n = s.size();

        if (freq[maxi] > (n + 1) / 2) return "";

        std::string res(n, ' ');
        int at = 0;

        while (freq[maxi]) {
            --freq[maxi];
            res[at] = maxi + 'a';
            at += 2;
        }

        for (int i = 0; i < 26; ++i) {
            while (freq[i]) {
                if (at >= res.size()) at = 1;

                --freq[i];
                res[at] = i + 'a';
                at += 2;
            }
        }

        return res;
    }
};