class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int freq[101]{};

        for (int s : stones) ++freq[s];

        int first = 100; int second = 100;
        while (first > 0) {
            if (freq[first] % 2 == 0) {
                --first;
                continue;
            }

            int j = first - 1;
            while (j > 0 && !freq[j]) --j;

            if (!freq[j]) return first;

            second = j;
            --freq[first];
            --freq[second];
            ++freq[first - second];

            first = std::max(second - first, second);
        }

        return first;
    }
};
