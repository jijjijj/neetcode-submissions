class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> ref;

        for (const char c : t) ++ref[c];

        const int need = ref.size();
        const int inf = std::numeric_limits<int>::max();

        int l = 0;
        int ans_l = 0;
        int ans_len = inf;
        int have = 0;

        std::unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); ++i) {
            if (++freq[s[i]] == ref[s[i]]) ++have;

            while (freq[s[l]] > ref[s[l]]) {
                --freq[s[l++]];
            }

            if (have == need) {
                if (ans_len > i - l + 1) {
                    ans_l = l;
                    ans_len = i - l + 1;
                }
            }
        }

        return ans_len == inf ? "" : s.substr(ans_l, ans_len);
    }
};
