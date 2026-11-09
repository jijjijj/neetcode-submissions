class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int n = p.size();

        std::vector<int> res;

        std::vector<int> ref(26);
        for (const char c : p) ++ref[c - 'a'];

        std::vector<int> freq(26);
        int matching = 0;
        const int need = std::count_if(ref.begin(), ref.end(), [](const auto& val) {
            return val;
        });

        int l = 0;
        for (int i = 0; i < s.size(); ++i) {
            const int c = s[i] - 'a';
            ++freq[c];

            if (freq[c] == ref[c] + 1) {
                --matching;
            } else if (freq[c] == ref[c]) {
                ++matching;
            }
            
            if (i >= n) {
                const int o = s[l++] - 'a';
                --freq[o];

                if (freq[o] == ref[o]) ++matching;
                else if (freq[o] + 1 == ref[o]) --matching;
            }

            if (matching == need) res.emplace_back(l);
        }

        return res;
    }
};
