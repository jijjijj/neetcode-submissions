class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::unordered_map<int, int> freq;

        int maxv = 0;
        for (int v : stones) {
            ++freq[v];
            maxv = std::max(maxv, v);
        }

        int i = maxv;

        while (i > 0) {
            if (!freq[i]) {
                --i;
                continue;
            }
            freq[i] &= 1;

            int small = i - 1;
            for (; small > 0; --small) {
                if (freq[small]) break;
            }

            if (small <= 0) return i;

            freq[i] = 0;
            freq[i - small] = 1;
            i = small;
        }

        return 0;
    }
};
