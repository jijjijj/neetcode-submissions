class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int curr = 0; // index
        int map[256];
        std::fill(map, map + 256, -1);

        for (int i = 0; i < s.size(); ++i) {
            const char c = s[i];
            while (map[c] != -1) {
                map[s[curr++]] = -1;
            }

            map[c] = i;
            max = std::max(max, i - curr + 1);
        }

        return max;
    }
};
