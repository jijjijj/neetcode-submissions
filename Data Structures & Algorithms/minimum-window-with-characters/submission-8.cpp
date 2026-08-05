class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> ref;

        for (const char c : t) ++ref[c];

        int l = 0;
        int ans_l = 0;
        int ans_len = 0;

        std::unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); ++i) {
            ++freq[s[i]];

            while (l < i && freq[s[l]] > ref[s[l]]) {
                --freq[s[l++]];
            }

            bool match = true;
            for (const auto [c, cnt] : ref) {
                if (freq[c] < cnt) {
                    match = false;
                    break;
                }
            }
            // if (match) std::cout << "t";
            if (match && (!ans_len || ans_len > i - l + 1)) {
                ans_l = l;
                ans_len = i - l + 1;
            }
        }

        return s.substr(ans_l, ans_len);
    }
};
