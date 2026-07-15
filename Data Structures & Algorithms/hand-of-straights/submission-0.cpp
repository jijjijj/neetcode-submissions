class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        std::unordered_map<int, int> freq;

        for (int card : hand) {
            ++freq[card];
        }

        bool possible = true;
        int left = hand.size();
        
        while (left >= groupSize) {
            int i = 0;
            for (; i <= 1000; ++i) {
                if (freq[i] > 0) break;
            }

            for (int j = 0; j < groupSize; ++j) {
                if (freq[i + j]-- == 0) {
                    return false;
                }
            }

            left -= groupSize;
        }

        return !left;
    }
};
