class Solution {
public:
    // sorting, priority-queue, ordered map, hash-map
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        std::ranges::sort(hand);
        
        std::unordered_map<int, int> freq;
        for (int n : hand) ++freq[n];

        for (int n : hand) {
            if (!freq[n]) continue;
             
            for (int i = n; i < n + groupSize; ++i) {
                if (!freq[i]) return false;

                --freq[i];
            }
        }

        return true;
    }
};
