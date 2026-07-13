class Solution {
public:
    string minWindow(string s, string t) {
        // if (t.size() > s.size()) return "";

        int ref[128] = {};

        for (char c : t) ++ref[c - 'A'];

        int freq[128] = {};
        int l = 0;
        int curr = 0;
        int minl = 0;
        int minlength = std::numeric_limits<int>::max();

        for (int r = 0; r < s.size(); ++r) {
            const char c = s[r] - 'A';
            ++freq[c];

            if (freq[c] <= ref[c]) ++curr;

            while (freq[s[l] - 'A'] > ref[s[l] - 'A']) {
                --freq[s[l++] - 'A'];
            }

            if (curr == t.size() && (r - l + 1) < minlength) {
                minl = l;
                minlength = r - l + 1;
            }
        }

        return minlength != std::numeric_limits<int>::max()
            ? s.substr(minl, minlength) : "";
    }
};
