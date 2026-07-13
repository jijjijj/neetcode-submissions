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

            // std::cout << curr << " " << ref[c] << " " << s[r] << std::endl;

            std::cout << s[r] << " " << l << std::endl;

            while (freq[s[l] - 'A'] > ref[s[l] - 'A']) {
                // if (freq[s[l] - 'A'] < ref[s[l] - 'A'])
                // curr -= !!ref[s[l] - 'A'];
                --freq[s[l] - 'A'];

                // std::cout << "> " << curr << " " << freq[s[l] - 'A'] << " " << s[l] << std::endl;

                ++l;
            }

            if (curr == t.size() && (r - l + 1) < minlength) {
                // std::cout << r << " " << s[r] << " " << curr << " " << freq[c] << std::endl;
                minl = l;
                minlength = r - l + 1;
            }
        }

        return minlength != std::numeric_limits<int>::max()
            ? s.substr(minl, minlength) : "";
    }
};
