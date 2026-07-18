class Solution {
public:
    // sorting, priority-queue, ordered map, hash-map
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        std::map<int, int> freq;
        for (int n : hand) ++freq[n];

        std::queue<int> q;
        int open = 0;
        int last = -1;

        for (auto [n, f] : freq) {
            if (f < open || (open && n > last + 1)) return false;

            q.push(f - open);
            open = f;
            last = n;

            if (q.size() == groupSize) {
                open -= q.front();
                q.pop();
            }
        }

        return !open;
    }
};
