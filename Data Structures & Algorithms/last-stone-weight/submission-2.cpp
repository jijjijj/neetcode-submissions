class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int freq[101]{};

        for (int s : stones) ++freq[s];

        int max = 0;
        for (int w = 100; w > 0; --w) {
            if (max) {
                freq[max] = freq[max] % 2 ? 1 : 0;
            }

            if (!max || !freq[max] && freq[w]) {
                max = w;
            }

            if (max != w && freq[w]) {
                --freq[max];
                --freq[w];

                ++freq[max - w];
                
                if (!freq[w]) max = 0;
            }
        }

        for (int w = 1; w <= 100; ++w) {
            if (freq[w]) return w;
        }
    }
};
