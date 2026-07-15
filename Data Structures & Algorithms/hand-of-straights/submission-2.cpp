class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        std::ranges::sort(hand);
        std::vector<bool> vis(hand.size());

        int left = hand.size();
        
        while (left >= groupSize) {
            int i = 0;
            
            while (i < hand.size()) {
                if (vis[i]) ++i;
                else break;
            }
            
            vis[i] = true;

            int j = 1;
            int k = 1;
            while (i + k < hand.size() && j < groupSize) {
                if (hand[i + k] > hand[i] + j) return false;
                if (hand[i + k] < hand[i] + j || vis[i + k]) {
                    ++k;
                    continue;
                }

                // std::cout << hand[i + k] << " ";
                vis[i + k] = true;
                ++j;
            }
            // std::cout << std::endl;
            if (j < groupSize) return false;
            left -= groupSize;
        }

        return !left;
    }
};
