class Solution {
public:
    // sorting, priority-queue, ordered map, hash-map
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        std::unordered_map<int, int> freq;
        for (int n : hand) ++freq[n];

        for (int n : hand) {
            int start = n;
            while (freq[start - 1]) --start;
            while (start <= n) {
                while (freq[start]) {
                    for (int i = start; i < start + groupSize; ++i) {
                        if (!freq[i]) return false;

                        --freq[i];
                    }
                }
                ++start;
            }
        }

        return true;
    }
};
