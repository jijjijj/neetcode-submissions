#include <ranges>

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        std::vector<int> o(26);
        for (int i = 0; i < order.size(); ++i) o[order[i] - 'a'] = i;
        
        const auto cmp =
            [&o](const std::string& a, const std::string& b) {
                for (int i = 0; i < std::min(a.size(), b.size()); ++i) {
                    if (a[i] != b[i])
                        return o[a[i] - 'a'] < o[b[i] - 'a'];
                }

                return a.size() < b.size();
            };

        return std::ranges::is_sorted(words, cmp);
    }
};